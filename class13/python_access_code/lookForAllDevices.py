import os
import atexit
import time
import Adafruit_BluefruitLE
import uuid
import binascii

ble = Adafruit_BluefruitLE.get_provider()
READ_UUID         = uuid.UUID('00002222-0000-1000-8000-00805F9B34FB')
MY_SERVICE_UUID   = uuid.UUID('00001111-0000-1000-8000-00805F9B34FB')

def int2bytes(i):
    hex_string = '%x' % i
    n = len(hex_string)
    return binascii.unhexlify(hex_string.zfill(n + (n & 1)))

def bytes2int(i):
    hex_string = binascii.hexlify(i)
    if (hex_string==""):
        return 0 
    return int(hex_string,16)

def main():
    ble.clear_cached_data()

    adapter = ble.get_default_adapter()
    adapter.power_on()
    print('Using adapter: {0}'.format(adapter.name))

    adapter.start_scan()
    
    atexit.register(adapter.stop_scan)
    print('Searching for devices ends with "Device"...')
    print('Press Ctrl-C to quit (will take ~30 seconds on OSX).')
    # Enter a loop and print out whenever a new UART device is found.
    valid_devices = set()
    statues_dictionary = dict()
    while True:
        found = set(ble.find_devices())
        for device in found:
        #    print('Found Device: {0} [{1}]'.format(device.name, device.id))
            if device.name and device.name.endswith("Device"):
                if device not in valid_devices:
                    valid_devices.add(device)
                    statues_dictionary[device]="found"
                    try:
                        device.connect(timeout_sec=10)
                        device.discover([MY_SERVICE_UUID], [READ_UUID])
                        statues_dictionary[device]="connected"
                    except: # catch *all* exceptions
                        valid_devices.remove(device)
        
        os.system('clear')
        print('Searching for devices ends with "Device"...')
        print('Press Ctrl-C to quit (will take ~30 seconds on OSX).')
        print('----------------------------------------------------')
        invalid_devices = set()
        for device in valid_devices:
            print('Found Device: {0} [{1}]'.format(device.name, device.id))
            try: 
                serviceObj = device.find_service(MY_SERVICE_UUID)
                readObj = serviceObj.find_characteristic(READ_UUID)
                response = readObj.read_value();
                print('\tstatues: '+statues_dictionary[device]+' value: '+hex(bytes2int(response)))
            except: # catch *all* exceptions
                print('\tstatues: '+'error')
                invalid_devices.add(device)
        valid_devices=valid_devices-invalid_devices
        # Sleep for a second and see if new devices have appeared.
        time.sleep(1.0)


# Initialize the BLE system.  MUST be called before other BLE calls!
ble.initialize()

# Start the mainloop to process BLE events, and run the provided function in
# a background thread.  When the provided main function stops running, returns
# an integer status code, or throws an error the program will exit.
ble.run_mainloop_with(main)
