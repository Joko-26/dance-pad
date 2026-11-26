---
title: "Dancepad"
github: "https://github.com/Joko-26/dance-pad"
description: "My first PCB ever!!\nA tiny reaction/speed figet toy based on the RP2040, with keyboard switches!!!\nIn short you have to press the corresponding button when an led lights up "
created_at: "2026-11-06"
total_time: "16h"
---

# November 6, 2026: Building the PCB (Design & Routing)
<!-- fabricate:entry 2276 -->

## HELLO everyone,
## This is the first time im creating a hardware Project and i wanted to start simple, so a build an very simple figet toy:

The PCB is based on the RP2024 (the same chip used by the rasberry pi pico. And the game is that you have to press the corresponding button when an led lights up (it will get faster the further you make it).

### The process

I started by watching a KiCad tutorial on Youtube (im not tracking that!!), then i started by making the shema (first pic).
which took a bit as i had to get familiar with the programm first.
Next i assigned the footprints (second pic) (god i have so much to learn, im so clueless about all of the different componts :( ).
But i managed to get all of the correct footprints so i routed the PCB next which was a little bit of a pain in the ass because the RP2040 seed im using and my placement of it wasnt so optimal for the pin layout so i had to route some of the wires on the bottom side (pic 3 & 4). At last i just filled the whole pcb with gnd so i didnt have to route that by hand.

**That was the process i**

I already learned so much and i hope my future Projects teach me even more!!

![](https://fabricate.hackclub-assets.com/c64eefe911bd64275ae185f16049476e568d570133b2df2386461e1e44a1fd83/image-png/Screenshot%202026-11-06%20205417.png)
![](https://fabricate.hackclub-assets.com/055dbcb14cbaf38f82e878e6f26c130d80a04a8da0f7ea00539c4349211d2cdf/image-png/Screenshot%202026-11-06%20205413.png)
![](https://fabricate.hackclub-assets.com/5c70d7ab446f65bc9f169e25669ac7fb6326a8679ba7f8135fe24161962bf915/image-png/Screenshot%202026-11-06%20205110.png)
![](https://fabricate.hackclub-assets.com/f1cb741e2512a284ce456ceb3713b0da64e1f31c7331536bf53faf4e0c0a8b05/image-png/Screenshot%202026-11-06%20204944.png)
![](https://fabricate.hackclub-assets.com/1e99a69e93c0096e0b8dfb10c165aa7641efae035514557225e708eb4bc4cc7c/image-png/Screenshot%202026-11-06%20204459.png)

**Total time spent: 6h**

# November 18, 2026: Added a 6 position rotary button for mode selection
<!-- fabricate:entry 3405 -->

## Hello everyone,

I added a rotary button for mode selection to the dance pad (the 3d model isnt the real one but for the purpose of jurnaling it should be sufficent). When ill make the software im planning on adding multiple modes/games which can be selected with the rotary button.

It was really difficuilt to find a suiting footprint for a 1 pin 6 pos button because almost all of the ones online are 2 pin 6 pos, but in the end i was able to find one on [Snapeda](https://www.snapeda.com/parts/SS-10-16SP-L-AEW/Nidec%20Copal/view-part/?ref=search&t=SS-10-16SP-L-AEW&ab_test_case=b) and a footprint on [ultralibrarian](https://app.ultralibrarian.com/details/1d1aaa46-78b9-11ed-b159-0a34d6323d74/Nidec-Copal-Electronics/SS-10-16SP-L-AEW). The next difficuilty was routing, i had to change some of the pins on the microcontroller so i had to redo some of my previous routing which took some time but in the end I managed to to it.

## Next up:
- code (building the firmware)
- odering (probably pcbway)

![](https://fabricate.hackclub-assets.com/e2ec9e7beb7a6e56d9fdba88dbafe1d45ef0f4d53366ae805f667b07ab9054b6/image-png/Screenshot%202026-11-18%20164210.png)
![](https://fabricate.hackclub-assets.com/a2c0e2b16cb90048b9fa832b27669e91a6d574fc95fb2273ebd1930d8abd1370/image-png/Screenshot%202026-11-18%20164201.png)
![](https://fabricate.hackclub-assets.com/3fb288b00a2deef9807278deeb5971f8fd3f1abb9e74132d095eb4f607e171cd/image-png/Screenshot%202026-11-18%20164836.png)

**Total time spent: 8h**

# November 25, 2026: made some firmware!!
<!-- fabricate:entry 3882 -->

## Hello everyone,

i have been busy making some firmware for the board, i added a memory game, where you have to remember the sequence of colors and repeat it. But thats not it i also made a reation game where you have to press the  right button as fast as possible. I didnt use ai for the code it self but i let it check for semicolon errors as the syntax highlighting doesnt work for some reason :(

Next ill make an enclosure using fusion 360 so i can 3d print it.

![](https://fabricate.hackclub-assets.com/6854b040699416c6a650940cd6ada89b28ce463caff92d82992cfa9f5d4f97c7/image-png/Screenshot%202026-11-25%20113547.png)

**Total time spent: 2h**
