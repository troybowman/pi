import sys
import subprocess
import shutil

subprocess.check_call(["/Users/Shared/Qt/5.5.1/bin/macdeployqt", "pi.app", "-use-debug-libs"])

shutil.copytree("/Users/Shared/Qt/5.5.1/lib/QtNetwork.framework", "pi.app/Contents/Frameworks/QtNetwork.framework", symlinks=True)

sys.path.append("/Users/troy/idasrc/third_party/misc_tools")
import package_utils
package_utils.make_macdeployqt_actually_work("/Users/Shared/Qt/5.5.1", "pi.app", "pi")
