import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/jn403l/Documents/ros2-sandbox/install/bumperbot_py_examples'
