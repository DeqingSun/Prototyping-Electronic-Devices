import os

script_dir = os.path.dirname(os.path.abspath(__file__))
hexfile_path = os.path.join(script_dir, 'sketch_ch571_ble_class.ino.hex')
wchisp_path = "/Users/deqinguser/Library/Arduino15/packages/WCH/tools/wchisp/0.3.0_20251008/wchisp"

os.system(f'"{wchisp_path}" --retry 30 config disable-debug')

os.system(f'"{wchisp_path}" --retry 2 flash "{hexfile_path}"')

