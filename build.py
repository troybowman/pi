import sys
import subprocess
import shutil
import os
import glob
import re

if sys.platform == "darwin":

    def patch_qt_install_names(lib):
        rpath_re = re.compile("(@rpath/Qt[^\s]+\.framework/Versions/[0-9]+/Qt[^\s]+).*")
        for line in subprocess.check_output(["otool", "-L", lib]).split("\n\t"):
            match = rpath_re.match(line)
            if match:
                orig = match.group(1)
                if not orig.endswith("_debug"):
                    dest = orig + "_debug"
                    argv = [ "install_name_tool", "-change", orig, dest, lib ]
                    print "patching install name: %s" % argv
                    subprocess.check_call(argv)

    # We use this to point idaq's install names to debug Qt frameworks, because of https://bugreports.qt.io/browse/QTBUG-48800.
    def make_macdeployqt_actually_work(qtdir, appdir, idaq):
        # patch idaq to refer to debug Qt Libs
        patch_qt_install_names(os.path.join(appdir, "Contents", "MacOS", idaq))
        # patch the debug Qt libs themselves
        for lib in glob.glob(os.path.join(appdir, "Contents", "Frameworks", "Qt*.framework", "Versions", "Current", "*_debug")):
            patch_qt_install_names(lib)
        # use libqcocoa_debug.dylib instead of libqcocoa.dylib, and patch it as well
        libqcocoa = os.path.join(appdir, "Contents", "PlugIns", "platforms", "libqcocoa%s.dylib")
        if os.path.isfile(libqcocoa % ""):
            os.remove(libqcocoa % "")
            shutil.copy(os.path.join(qtdir, "plugins", "platforms", "libqcocoa_debug.dylib"), os.path.dirname(libqcocoa))
            patch_qt_install_names(libqcocoa % "_debug")

    shutil.rmtree(".qmake.stash", ignore_errors=True)
    shutil.rmtree("pi.app", ignore_errors=True)
    subprocess.check_call(["make", "clean"])
    subprocess.check_call(["make"])
    subprocess.check_call(["/Users/Shared/Qt/5.6.3-x64/bin/macdeployqt", "pi.app", "-use-debug-libs"])
    shutil.copytree("/Users/Shared/Qt/5.6.3-x64/lib/QtNetwork.framework", "pi.app/Contents/Frameworks/QtNetwork.framework", symlinks=True)
    make_macdeployqt_actually_work("/Users/Shared/Qt/5.6.3-x64", "pi.app", "pi")

elif sys.platform == "win32":

    subprocess.check_call(["nmake", "clean"])
    subprocess.check_call(["C:\\Qt\\5.6.3-x64\\bin\\qmake"])
    subprocess.check_call(["nmake"])
    subprocess.check_call(["C:\\Qt\\5.6.3-x64\\bin\\windeployqt", "pi.exe"])
