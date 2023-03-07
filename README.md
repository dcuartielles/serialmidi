
# SerialMidi

Command line script to bridge Serial to MIDI.

Code and original instructions by **raspy135** at the [serialmidi repository](https://github.com/raspy135/serialmidi)

Works with any micro controller boards such as Arduino, ESP32, using their UART-USB interface.

Processes most of MIDI messages. Has very low latency (probably less than 5ms).

## Requirements / Installation

This script needs [python-rtmidi](https://pypi.org/project/python-rtmidi/), [PySerial](https://pypi.org/project/pyserial/) and Python 3.

1. Install Python 3 (MACs come with this by default)
2. Install pip (MACs come with this by default)
3. In a terminal window, execute `pip3 install python-rtmidi`
4. In a terminal window, execute `pip install pyserial`
5. Download `serialmidi.py` from [this link](https://raw.githubusercontent.com/dcuartielles/serialmidi/master/serialmidi.py) in the repository, copy it in a folder of your liking

## Quickstart

1. In a terminal window, navigate to the folder where you downloaded the `serialmidi.py` program using `cd NAME_OF_FOLDER`
2. Using the Arduino IDE, identify the port your Arduino is connected to. In MAC OS X, the port will be called `/dev/cu.usbmodemXXX`, in Windows `COMXXX` and in Linux `/dev/ttyACMXXX`, where `XXX` represents a unique identifying number.
3. Make sure your microcontroller board is running a code that could be used to trigger your midi device. For example, the [following code example]() is used at Malmo University, Sweden, to convert an Arduino Uno into a midi device interfacing Ableton Live.
4. Configure your virtual midi device input / ouput in your computer so that the port name is `IAC` for MAC or `loopMIDI` for Windows. Check the small details that might affect the configuration, i.e. in Swedish computers, the communication bus is called `Buss` (with two `s`).
5. In a terminal window, and depending on your operating system, use the following code to start the communication, change `SLAB_USBtoUART` to correspond the serial port you will be using.

```
MAC OS X / Linux example
$ python3 serialmidi.py --serial_name=/dev/cu.SLAB_USBtoUART --midi_in_name="IAC Bus 1" --midi_out_name="IAC Bus 2"

WINDOWS example
$ python.exe .\serialmidi.py --serial_name=COM4 --midi_in_name="loopMIDI Port IN 0" --midi_out_name="loopMIDI Port OUT 2"
```

## Testing the setup

1. Run `serialmidi.py -h` to see this help.
```
$ python3 serialmidi.py -h
usage: serialmidi.py [-h] --serial_name SERIAL_NAME [--baud BAUD]
                     [--midi_in_name MIDI_IN_NAME]
                     [--midi_out_name MIDI_OUT_NAME] [--debug]

Serial MIDI bridge

optional arguments:
  -h, --help            show this help message and exit
  --serial_name SERIAL_NAME
                        Serial port name. Required
  --baud BAUD           baud rate. Default is 115200
  --midi_in_name MIDI_IN_NAME
  --midi_out_name MIDI_OUT_NAME
  --debug               Print incoming / outgoing MIDI signals
```

2. Figure out serial port name and baud rate. Baud rate default is 115200.
3. Run `serialmidi.py --serial_name=[serial_port] --baud=[baud]`. Make sure it doesn't say "Serial port opening error.".
4. The script prints recognized MIDI devices. Use one of listed name as argument of `--midi_in_name` and `--midi_out_name`. Here is an example on OS X.
```
INFO:root:IN : 'IAC Bus 1','IAC Bus 2'
INFO:root:OUT : 'IAC Bus 1','IAC Bus 2'
```
You may want to use MIDI loop bus such as IAC Bus for OS X, or [loopMIDI](https://www.tobias-erichsen.de/software/loopmidi.html) for Windows. Also, you need to use different bus in order to avoid signal loop.

5. If it is not working, try `--debug` option. It will dump all incoming / outgoing MIDI messages. Or create an issue on the GitHub page.


## Tested environment
- Tested with OS X Catalina with ESP32 board, and Windows10 with loopMIDI.

## Disclaimer
- It's originally made for a DIY ESP32-based synthesizer, MIDI IN has been extensively tested, but MIDI OUT might throw some errors.


