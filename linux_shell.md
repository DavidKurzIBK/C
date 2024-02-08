# Kurze Einführung in Linux

Dieses Dokument bietet eine Übersicht über einige Aspekte von Linux.
Es basiert auf Folien von Stefan Podlipnig und vielen anderen.

## Shell

- Primäre Schnittstelle zum System
- Kommandozeileninterpreter
    + Übernimmt einen Befehl
    + Interpretiert ihn
    + Führt ihn aus
    + Wartet auf den nächsten Befehl
- Standard Befehlssyntax: `command [flags] [files]`
    + `gcc –Wall –Werror –std=c99 –o test test.c`
    + `pwd`
    + `ls -a`
    + `cd EidP`

## Linux Dateisystem

- Hierarchische Organisationsstruktur für Daten
- Die Wurzel (engl. root) der Struktur ist `/`
- Ordner im Dateipfad werden durch `/` getrennt
- Alle Daten werden als Dateien (engl. files) interpretiert
- Dateizugriffsrechte
    + Lesen (engl. read)
    + Schreiben (engl. write)
    + Ausführen (engl. execute)
- Hilfreiche Befehle
    + `pwd` - print working directory
    + `cd` - change directory
    + `mkdir` - make directory
- Besondere Platzhalter
    + `.` - Aktuelles Verzeichnis
    + `..` - Übergeordnetes Verzeichnis
    + `~` - `home` Verzeichnis des Users
- Absolute und relative Pfade
    + `cd /home/csax001/Studium/EidP/s01` - Absoluter Pfad
    + `cd ../s02` - Relativer Pfad

## Arbeiten mit Dateien
	
- Hilfreiche Befehle
    + `ls` - list directory contents
    + `cat` - concatenate and print files
    + `rm` - remove files or directories
    + `mv` - move (rename) files
    + `cp` - copy files and directories
- Editoren
    + `nano`
    + `vi`, `vim`
    + `emacs`
    + `geany`
    + `Visual Studio Code`
    + `...`


## Beispiel

```bash
$ cd /home/csax001/Studium/EidP/s01
$ pwd
/home/csax001/Studium/EidP/s01
$ cd ../s02
$ pwd
/home/csax001/Studium/EidP/s02
$ cd ..
$ ls
s01 s02
$ mkdir s03
$ ls
s01 s02 s03
$ tar -czvf s01.tar.gz s01
$ ls
s01 s01.tar.gz s02 s03
```

## Der wichtigste Befehl - `man`

- Dokumentation für jeden Befehl
- Aufgeteilt in verschiedene Abschnitte (engl. section)
	+  `1` - General Commands
	+  `2` - System Calls
	+  `3` - Library functions, covering in particular the C standard library
	+  ...
- `man [flags] <command>`
    + `man gcc` - Dokumentation des Befehls `gcc` (section 1)
    + `man 3 printf` - Dokumentation des Befehls `printf` (section 3)
    + `man man` - Manpages des Befehls `man` (section 1)
    + `man -k ls` - Auflistung aller Manpages für den Befehl `ls`
- Shortcuts
    + Navigation: Pfeiltasten, `d` (halbe Seite nach oben), `u` (halbe Seite nach unten), ...
    + Suche: `/` (Vorwärtssuche), `?` (Rückwärtssuche), `n`/`N` vor/zurück 
    + Beenden: `q`
    + Hilfe: `h`

## Shell Shortcuts

- `Strg + c` - Beende den aktuellen Prozess
- `Strg + r` - Suche im Verlauf
- `Strg + a` - Springe an den Anfang der Zeile
- `Strg + e` - Springe an das Ende der Zeile
- `Strg + l` - Setze den Cursor an den Anfang


## Hilfreiche Befehle

- Zugang zum Uni Netzwerk von außerhalb: [https://www.uibk.ac.at/zid/netz-komm/vpn/](https://www.uibk.ac.at/zid/netz-komm/vpn/)
- `ssh` - OpenSSH SSH client (remote login program)
- `scp` - secure copy (remote file copy program)
- Datei Transfer unter Windows: [https://www.uibk.ac.at/zid/systeme/webserver/winscp/](https://www.uibk.ac.at/zid/systeme/webserver/winscp/) als Rechnername `zid-gpl.uibk.ac.at` verwenden. 
		
Login, wenn im Uni Netzwerk:

```bash
ssh -X -l <user> zid-gpl.uibk.ac.at
```

Kopieren einer Datei, wenn im Uni Netzwerk von UNIX/Linux System:

```bash
scp <file> <user>@zid-gpl.uibk.ac.at:/home/<user>/
```
