# Open/Close Sensor Example Application

## Design
The open/close sensor example application uses the Weave Data Management protocol (WDM) to enable remote access to state of a simulated open/close sensor.  The
application implements the standard Nest-defined schema for a consumer-grade open/close sensor.  In particular, the application publishes the `security.SecurityOpenCloseTrait`, which
it uses to expose the overall state of the sensor placed on a window or a door, to outside consumers.  In turn, the application consumes the properties of the `security.DeviceLocatedSettingsTrait`
as published by the Nest service.  These properties contain user-supplied settings that configure the desired behavior of the device.

Whenever the open close state of door/window changes, the application emits a `SecurityOpenCloseEvent`. 
This event describes the end result of the change (current open/close state), the state before 
the change and bypass state (not used in this example). This is conveyed to the Nest service 
in a reliable manner.

Together, the features of the open close sensor example have been designed to illustrate the four core interaction patterns typical of devices that use Weave and the Weave Data Management protocol; namely:

As part of implementing the BoltLockTrait, the application also responds to `BoltLockChangeRequest` commands instructing it to change the state of the bolt.  This
provides the ability to remotely lock and unlock the door.  To better simulate real lock hardware, the application incorporates a short delay mimicking the actuation
time of the bolt.

Whenever the state of the bolt changes, the application emits a `BoltActuatorStateChangeEvent`.  This event describes the end result of the change (bolt extended or
retracted), when the change happened and the actor or action that initiated it.  This is conveyed to the Nest service in a reliable manner.

Together, the features of the lock example have been designed to illustrate three core interaction 
patterns typical of devices that use Weave and the
Weave Data Management protocol; namely:

- Publishing local state
- Subscribing to remote settings
- Emitting events

<a name="device-ui"></a>

## Device UI

The example application provides a simple UI that depicts the state of the device and offers basic user control.
This UI is implemented via the general-purpose LEDs and buttons built of the hardware platform dev board.

**LED #1** shows the overall state of the device and its connectivity.  Four states are depicted:

- *Short Flash On (50ms on/950ms off)* &mdash; The device is in an unprovisioned (unpaired) state and is waiting for a commissioning application to connect.


- *Rapid Even Flashing (100ms on/100ms off)* &mdash; The device is in an unprovisioned state and a commissioning application is connected via BLE.


- *Short Flash Off (950ms on/50ms off)* &mdash; The device is full provisioned, but does not yet have full network (Thread) or service connectivity.


- *Solid On* &mdash; The device is fully provisioned and has full network and service connectivity.


**Button #1** can be used to initiate a OTA software update as well as to reset the device to a default state. 

A brief press of Button #1 instructs the device to perform a software update query to the Nest service.  Should the service indicate a software update is  available, the device
will download the corresponding software image file.  This feature is only available once the device completed the pairing process. While software update is running, another brief press on Button #1 will abort it.

Pressing and holding Button #1 for 6 seconds initiates a factory reset.  After an initial period of 3 seconds, all four LED will flash in unison to signal the pending reset.  Holding the button past 6 seconds
will cause the device to reset its persistent configuration and initiate a reboot.  The reset action can be cancelled by releasing the button at any point before the 6 second limit.

**LED #2** shows the open/close state detected by the sensor. When the LED is not lit the the sensor detects 
door/window OPEN; when lit, the sensor detects door/window CLOSE.

**Button #2** can be used to change the state of the simulated door/window. This can be used to mimick 
a user manually opening/closing the door/window. The button behaves as a toggle, swapping the state 
every time it is pressed.

The remaining two LEDs and buttons (#3 and #4) are unused.

## Platform-specific Information

- [Nordic nRF5x](../../common/platforms/nrf5/README.md)
- [Silicon Labs EFR32](../../common/platforms/efr32/README.md)
