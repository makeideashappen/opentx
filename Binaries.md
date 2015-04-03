# Download the latest openTx versions #

The memory size of the '9x radio is limited and it is not possible to add all features to the radio at the same time. In order to provide you with exactly the functions you need, the companion9x program can request  the build server to prepare a custom openTx version for you. companion9x will then automatically download your customized version and make it available for flashing to your radio.

For further information about companion9x, have a look at the project website: http://code.google.com/p/companion9x/

The following configuration options are currently available in companion9x:

| **Option** | **Explanation** |
|:-----------|:----------------|
| PCB | The main board of the transmitter can be replaced by more powerful board versions that provide more features and computing power. openTx is available for the stock PCB, the gruvin9x v4 PCB or the ersky9x PCB |
| Language | All openTx versions are available in any of the following langauges: Czech, English, French, German, Italian, Swedish |
| frsky| Support for the Fr-Sky telemetry enabled radio system with telemetry data display on the '9x transmitter screen. That means that there is no need for an external telemetry screen! All telemetry systems require hardware modifications of the radio. |
| nogauges| Disable display of telemetry data as gauges, spares some flash. |
| nogpg| Disable support of gps data in telemetry, spares 1.5KB of flash. |
| jeti | Also a telemetry system |
| ardupilot |  Also a telemetry system  |
| nmea |  Also a telemetry system  |
| heli | Includes a configuration page for helicopters. If you do not fly helicopters you do not need this page. |
| templates | Includes a configuration page with templates for a number of common types of models. A more advanced user will typically remove this page to preserve space. |
| nosplash | Used to remove splash screen and preserve space for other options. |
| nofp | Removes Flight Phases configuration page to simplify setup and preserve space. |
| audio | The standard beep of the radio is horrible. It is possible to make a HW mod for this and this option makes it possible to control that modification |
| haptic | Support for haptic HW modification of the radio (that is addition of vibrations during the beeps) |
| PXX | Support for PXX radio protocol |
| DSM2 | Support for DSM2 radio protocol |
| ppmca | Adds possibility for PPM center adjustment |
| ppmus | Display PPM informations using uS as units |
| gvars | Add support for global vars |
| potscroll | Uses potentiometers to scroll in menus. |
| autoswitch | During model setup it is possible to select and set switches by moving them. |
| nographics | Disabling graphic of sliders and check boxes |
| pgbar | Shows a small progress bar when data are stored in the transmitter memory |
| imperial | Uses imperial units rather than the standard metric ones. |
| voice | Add support for voice, remember to choose your language and download appropriate sound pack. |