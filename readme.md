# QMK Firmware bm40hsrgb v2 Neo Bone


<p float="left">
    <img src="./keyboards/kprepublic/bm40hsrgb/rev2/_github_example_pictures//layer1.png"  width="45.5%" height="45.5%">
    <img src="./keyboards/kprepublic/bm40hsrgb/rev2/_github_example_pictures/1.jpeg"  width="40%" height="40%">
</p>

Forked from qmk firmware und so angepasst, sodass mein bm40hsrgb v2 keyboard mit meinem custom [Neo Bone layout](https://www.neo-layout.org/Layouts/bone/) funktioniert. Benutzt mehrere Layers und Taps_word (Caps_Word).

## Table Of Content

- [Getting Started](#getting-started)
  - [Dependencies](#dependencies)
  - [Installation](#installation)
  - [Compile and run](#compile-and-run)
- [Vizualise Keymap](#vizualise-keymap)
- [Example pictures](#example-pictures)
- [Original readme of forked repo](#quantum-mechanical-keyboard-firmware)


## Getting Started

### Dependencies

In order for the scripts to work you will need the following dependencies:
 * C compiler
 * make

### Installation
 - make sure that your pc uses an english keyboard layout. But for maximum compatibility use [EurKey](https://eurkey.steffen.bruentjen.eu/layout.html) 
 - `git clone https://github.com/thob97/qmk_firmware_bm40hsrgb_v2_Neo_Bone.git`
 - `cd qmk_firmware_bm40hsrgb_v2_Neo_Bone/keyboards/kprepublic/bm40hsrgb/rev2/`

### Compile and run
 - `make kprepublic/bm40hsrgb/rev2:default:flash`
 - `echo 'PATH="$HOME/.local/bin:$PATH"' >> $HOME/.bashrc && source $HOME/.bashrc`

## Vizualise Keymap:
The pdf for a visualized representation of the keymap was created with: https://config.qmk.fm/#/kprepublic/bm40hsrgb/LAYOUT_planck_mit.
This is for visual representation only! Some keys differ with this json file/ on this website, as they can not be represented on them. (e.g. reset key needs to be pressed 10times for ist functionality -> this can not be represented in the website )


## Example pictures
<p float="left">
    <img src="./keyboards/kprepublic/bm40hsrgb/rev2/_github_example_pictures/preview1.jpeg"  width="48%" height="48%">
    <img src="./keyboards/kprepublic/bm40hsrgb/rev2/_github_example_pictures/2.JPG"  width="48%" height="48%">
</p>
<p float="left">
    <img src="./keyboards/kprepublic/bm40hsrgb/rev2/_github_example_pictures/layer1.png"  width="48%" height="48%">
    <img src="./keyboards/kprepublic/bm40hsrgb/rev2/_github_example_pictures/layer2.png"  width="48%" height="48%">
    <img src="./keyboards/kprepublic/bm40hsrgb/rev2/_github_example_pictures/layer3.png"  width="48%" height="48%">
    <img src="./keyboards/kprepublic/bm40hsrgb/rev2/_github_example_pictures/layer4.png"  width="48%" height="48%">
    <img src="./keyboards/kprepublic/bm40hsrgb/rev2/_github_example_pictures/layer5.png"  width="48%" height="48%">

</p>

<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>

# Quantum Mechanical Keyboard Firmware

[![Current Version](https://img.shields.io/github/tag/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/tags)
[![Discord](https://img.shields.io/discord/440868230475677696.svg)](https://discord.gg/Uq7gcHh)
[![Docs Status](https://img.shields.io/badge/docs-ready-orange.svg)](https://docs.qmk.fm)
[![GitHub contributors](https://img.shields.io/github/contributors/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/pulse/monthly)
[![GitHub forks](https://img.shields.io/github/forks/qmk/qmk_firmware.svg?style=social&label=Fork)](https://github.com/qmk/qmk_firmware/)

This is a keyboard firmware based on the [tmk\_keyboard firmware](https://github.com/tmk/tmk_keyboard) with some useful features for Atmel AVR and ARM controllers, and more specifically, the [OLKB product line](https://olkb.com), the [ErgoDox EZ](https://ergodox-ez.com) keyboard, and the [Clueboard product line](https://clueboard.co).

## Documentation

* [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)

The docs are powered by [Docsify](https://docsify.js.org/) and hosted on [GitHub](/docs/). They are also viewable offline; see [Previewing the Documentation](https://docs.qmk.fm/#/contributing?id=previewing-the-documentation) for more details.

You can request changes by making a fork and opening a [pull request](https://github.com/qmk/qmk_firmware/pulls), or by clicking the "Edit this page" link at the bottom of any page.

## Supported Keyboards

* [Planck](/keyboards/planck/)
* [Preonic](/keyboards/preonic/)
* [ErgoDox EZ](/keyboards/ergodox_ez/)
* [Clueboard](/keyboards/clueboard/)
* [Cluepad](/keyboards/clueboard/17/)
* [Atreus](/keyboards/atreus/)

The project also includes community support for [lots of other keyboards](/keyboards/).

## Maintainers

QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [ZSA Technology Labs](https://github.com/zsa), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
