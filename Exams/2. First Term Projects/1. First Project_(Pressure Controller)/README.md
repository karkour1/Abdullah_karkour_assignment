# Cabin Pressure Controller

This project implements a cabin pressure controller that monitors the pressure inside a cabin and triggers an alarm if the pressure exceeds 20 bars.

## Functionality

The cabin pressure controller performs the following tasks:
- Monitors the pressure inside the cabin.
- Triggers an alarm if the pressure exceeds 20 bars.
- Activates the alarm for a duration of 60 seconds.

## Assumptions

The following assumptions are made in this project:
- **Setup and Shutdown Procedures**: 
  - The specification does not include modeling setup and shutdown procedures for the controller.
- **Maintenance**: 
  - Maintenance activities for the controller are not modeled.
- **Sensor Reliability**: 
  - It is assumed that the pressure sensor never fails.
- **Alarm Reliability**: 
  - It is assumed that the alarm system never fails.
- **Power Supply**: 
  - The controller assumes a consistent power supply and does not model power cuts.

## Usage

To use the cabin pressure controller:
1. Ensure the pressure sensor is properly connected to the controller.
2. Power up the controller.
3. The controller will continuously monitor the cabin pressure.
4. If the pressure exceeds 20 bars, the alarm will be triggered for 60 seconds.s 60 seconds.

