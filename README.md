# DBI English Translation

This repository contains an English translation for the DBI homebrew application (version 810) for Nintendo Switch.

Was updating my Switch installation and wanted to bump DBI version from original 500-something. So, fired up Ghidra, 
investigated suspicious chunk of referenced memory and sure enough, there was naive xor cipher on compressed strings.

With cyrillic obviously being inferior to latin alphabet (:D) and taking mostly two bytes per character, there was no 
issue in fiting english texts to available space.

I do not intend to maintain this repo and play cat-and-mouse games with DBI author. Original version was working fine 
for years, so hopefuly there will be at least one similiary stable version released to this point. Would be of course
cool if he stopped playing princess and released multilanguage version, yet I dont expect that.

Also, I guess we will finally see for sure if there is any console bricking code and if he wants to exercise it.

Everything should be hopefuly clear from code. AI-generated generic readme follows.

## Important Disclaimers

### Author Controversy
This translation is provided independently and is not affiliated with or endorsed by the original DBI author. Users should be aware of ongoing community discussions regarding the original software and make informed decisions about its use.

### Backup Your Console
**Before using any homebrew software, create a complete backup of your console:**
- NAND backup
- Console keys (prod.keys, title.keys)
- SD card contents

Store these backups in multiple secure locations. Console bricks can and do happen.

### No Warranties
This translation is provided as-is with no guarantees whatsoever. The author of this translation accepts no responsibility for any damage, data loss, console bricks, account bans, or other issues that may arise from using this modified software. Use at your own risk.

### Potential Countermeasures
The original author may implement measures in future DBI releases to detect or prevent these translations from functioning. This repository may become obsolete without warning.

### Maintenance Notice
This repository is not actively maintained. Future DBI updates will likely break compatibility, and no fixes are planned. The community is free to fork, modify, and distribute this work as needed.

## Technical Notes

### Testing Status
This translation has received limited testing beyond basic functionality:
- SD card browsing
- Application installation via MTP

Simply just clicked through menus and everything seemed to be reasonably working. No immediate console combustion.

### Translation Method
The translation was generated primarily through automated tools (Perplexity AI) with manual corrections (because I dont speak Russian, obviously). 
Some translations may be imprecise or contextually incorrect. Just linked the english/russian readmes for context.

### Code Quality
This is experimental software built on previous vibe-coded python porn. The codebase is functional but not production-ready.

### String Placeholder Matching
When modifying translations, ensure string placeholders match between original and translated files. Use the `--keys` parameter 
and diff the resulting files to identify critical changes that could break functionality. This is just basic test, best
would be of course manualy checking all strings.

## Usage

### Quick Start (Version 810)
```bash
git clone <repository-url>
cd <repository-directory>
make translate-810
```

### Manual Usage
The `dbipatcher` utility provides several operations:

```
Usage: ./bin/dbipatcher [OPTIONS]

Options:
  -b, --binary FILE      Input binary file to patch
  -p, --patch FILE       Patch file to apply
  -o, --output FILE      Output file or directory
  -k, --keys FILE        Output file or directory
  -s, --slot NUMBER      Slot index for patch application
  -e, --extract FILE     Extract payloads from a DBI binary
  -c, --convert FILE     Convert payload or translation file
  -h, --help             Display this help message

Examples:
  # Extract payloads from DBI.nro into folder DBI_extract
     dbipatcher --extract DBI.810.ru.nro --output DBI_extract

  # Convert extracted payload 6.bin into an editable text file
     dbipatcher --convert DBI_extract/rec6.bin --output translation.txt --keys keylist.txt

  # Convert edited translations back into binary form
     dbipatcher --convert rec6.810.en.txt --output DBI_extract/rec6.bin --keys keylist.txt

  # Apply patch 6.bin to DBI.nro at slot 6 and write patched binary
     dbipatcher --patch DBI_extract/rec6.bin --binary DBI.810.ru.nro --slot 6 --output DBI.patched.nro
```

## Legal Notice

This translation is distributed for educational and interoperability purposes. Users are responsible for complying with applicable laws and terms of service in their jurisdiction.

## License

This translation work is released into the public domain. The original DBI software remains under its original license terms.
