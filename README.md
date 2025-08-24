# Super Mario 64 EX – Original Xbox Port

This is a port of **Super Mario 64 EX** for the **Original Xbox**.  

> ⚠️⚠️⚠️ 99% of the work comes from [mborgerson’s port/renderer](https://github.com/mborgerson/xsm64) (done back in 2020).  

What I did was fix the issues that prevented it from compiling on modern **NXDK**, and then migrated the code over to **Super Mario 64 EX** (a more enhanced and mod-compatible Mario 64 PC port).

## How to build:
- Install and set up NXDK https://github.com/XboxDev/nxdk
- I personally use WSL Ubuntu 22.04.5 on Windows 11 for NXDK stuf
- Clone this repo
- Place a Super Mario 64 ROM called baserom.<VERSION>.z64 into the repository's root directory for asset extraction, where VERSION can be us, jp, or eu
- Open a terminal and run the NXDK activation script (./nxdk/bin/activate)
- Run `make TARGET_XBOX=1 -jX` where x is the number of CPU threads you want to use (or leave the flag out)
- You should end up with `sm64ex.iso` in the root folder and a `default.xbe` in the `bin` folder
- Either burn `sm64ex.iso` to a DVD (or load in XEMU) or copy `default.xbe` to your Xbox HDD

## Credits
- [mborgerson](https://github.com/mborgerson) — Original Xbox port/renderer work  
- The **NXDK** folk — Xbox homebrew development kit
- The **sm64ex** project — Enhanced Mario 64 PC port
- The **Xbox Scene at large**

---------------------------------------
ORIGINAL README BELOW:
---------------------------------------
# sm64ex
Fork of [sm64-port/sm64-port](https://github.com/sm64-port/sm64-port) with additional features. 

Feel free to report bugs and contribute, but remember, there must be **no upload of any copyrighted asset**. 
Run `./extract_assets.py --clean && make clean` or `make distclean` to remove ROM-originated content.

Please contribute **first** to the [nightly branch](https://github.com/sm64pc/sm64ex/tree/nightly/). New functionality will be merged to master once they're considered to be well-tested.

*Read this in other languages: [Español](README_es_ES.md), [Português](README_pt_BR.md), [简体中文](README_zh_CN.md) or [Bahasa Melayu](README_ms_MY.md).*

## New features

 * Options menu with various settings, including button remapping.
 * Optional external data loading (so far only textures and assembled soundbanks), providing support for custom texture packs.
 * Optional analog camera and mouse look (using [Puppycam](https://github.com/FazanaJ/puppycam)).
 * Optional OpenGL1.3-based renderer for older machines, as well as the original GL2.1, D3D11 and D3D12 renderers from Emill's [n64-fast3d-engine](https://github.com/Emill/n64-fast3d-engine/).
 * Option to disable drawing distances.
 * Optional model and texture fixes (e.g. the smoke texture).
 * Skip introductory Peach & Lakitu cutscenes with the `--skip-intro` CLI option
 * Cheats menu in Options (activate with `--cheats` or by pressing L thrice in the pause menu).
 * Support for both little-endian and big-endian save files (meaning you can use save files from both sm64-port and most emulators), as well as an optional text-based save format.

Recent changes in Nightly have moved the save and configuration file path to `%HOMEPATH%\AppData\Roaming\sm64ex` on Windows and `$HOME/.local/share/sm64ex` on Linux. This behaviour can be changed with the `--savepath` CLI option.
For example `--savepath .` will read saves from the current directory (which not always matches the exe directory, but most of the time it does);
   `--savepath '!'` will read saves from the executable directory.

## Building
For building instructions, please refer to the [wiki](https://github.com/sm64pc/sm64ex/wiki).

**Make sure you have MXE first before attempting to compile for Windows on Linux and WSL. Follow the guide on the wiki.**
