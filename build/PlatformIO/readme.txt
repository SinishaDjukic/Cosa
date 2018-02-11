Installation
=============
Until Cosa is published as a standard PlatformIO framework the following instructions apply for local installations:

1) Copy the Cosa project root to the Platformio "packages" folder and rename as "framework-cosa":
    <Cosa project root> -> ~/./platformio/packages/framework-cosa

2) Copy the "cosa.py" build script to the "atmelavr" framework build scripts:
    <Cosa project root>/build/PlatformIO/platform/cosa/builder/frameworks/cosa.py
      -> ~/./platformio/platforms/atmelavr/builder/frameworks/cosa.py

3) Add Cosa to the list of supported frameworks in "atmelavr". Edit:
   ~/./platformio/platforms/atmelavr/platform.json
   
   Add this section to "frameworks":
   "cosa": {
      "package": "framework-cosa",
      "script": "builder/frameworks/cosa.py"
    }
    
    Add this section to "packages":
    "framework-cosa": {
      "type": "framework",
      "optional": true,
      "version": ">=1.2.100"
    }
    
4) Board definitions should be edited to support the Cosa framework. E.g. ~/./platformio/platforms/atmelavr/boards/uno.json should be updated as follows:
  "frameworks": [
    "arduino",
    "simba",
	"cosa"
  ]


Project Configuration
=====================
Projects using Cosa use the framework value "cosa" in platformio.ini:
	platform = atmelavr
	framework = cosa

To test it out you can use the sample build project "<Cosa project root>/build/PlatformIO/CosaBuild" and run
    platformio run

