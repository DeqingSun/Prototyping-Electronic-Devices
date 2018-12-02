import Adafruit_BluefruitLE
from Adafruit_BluefruitLE.services import DeviceInformation
import uuid
import binascii

#modify name to your's
PERIPHERAL_NAME   = 'DeqingDevice'

# Define service and characteristic UUIDs used by the UART service.
READ_UUID         = uuid.UUID('00002222-0000-1000-8000-00805F9B34FB')
MY_SERVICE_UUID   = uuid.UUID('00001111-0000-1000-8000-00805F9B34FB')
# '0000XXXX-0000-1000-8000-00805F9B34FB'
# If you use 16bit/4HEX UUID, replace XXXX with your hex 

def int2bytes(i):
    hex_string = '%x' % i
    n = len(hex_string)
    return binascii.unhexlify(hex_string.zfill(n + (n & 1)))

def bytes2int(i):
    hex_string = binascii.hexlify(i)
    if (hex_string==""):
        return 0 
    return int(hex_string,16)

# Get the BLE provider for the current platform.
ble = Adafruit_BluefruitLE.get_provider()

# Main function implements the program logic so it can run in a background
# thread.  Most platforms require the main thread to handle GUI events and other
# asyncronous events like BLE actions.  All of the threading logic is taken care
# of automatically though and you just need to provide a main function that uses
# the BLE provider.
def main():
    # Clear any cached data because both bluez and CoreBluetooth have issues with
    # caching data and it going stale.
    ble.clear_cached_data()

    # Get the first available BLE network adapter and make sure it's powered on.
    adapter = ble.get_default_adapter()
    adapter.power_on()
    print('Using adapter: {0}'.format(adapter.name))

    print('Searching for device...')
    try:
        adapter.start_scan()
        # Search for the first UART device found (will time out after 60 seconds
        # but you can specify an optional timeout_sec parameter to change it).
        device = ble.find_device(name=PERIPHERAL_NAME,timeout_sec=10)
        if device is None:
            raise RuntimeError('Failed to find peripheral device!')
    finally:
        # Make sure scanning is stopped before exiting.
        adapter.stop_scan()

    print('Connecting to device...')
    device.connect(timeout_sec=10)  # Will time out after 60 seconds, specify timeout_sec parameter
                      # to change the timeout.
    
    print('Connected to device')
    print('Connected DEVICE: {0} [{1}]'.format(device.name, device.id))

    # Once connected do everything else in a try/finally to make sure the device
    # is disconnected when done.
    try:
        # Wait for service discovery to complete for at least the specified
        # service and characteristic UUID lists.  Will time out after 60 seconds
        # (specify timeout_sec parameter to override).
        print('Discovering services...')
        device.discover([MY_SERVICE_UUID], [READ_UUID])

        # Find the UART service and its characteristics.
        serviceObj = device.find_service(MY_SERVICE_UUID)
        readObj = serviceObj.find_characteristic(READ_UUID)
        response = readObj.read_value();
        value=bytes2int(response)
        
        print hex(value)

        print('Access finished')
    finally:
        # Make sure device is disconnected on exit.
        device.disconnect()


# Initialize the BLE system.  MUST be called before other BLE calls!
ble.initialize()

# Start the mainloop to process BLE events, and run the provided function in
# a background thread.  When the provided main function stops running, returns
# an integer status code, or throws an error the program will exit.
ble.run_mainloop_with(main)
