## TODO!

- [x] Lägga in alla värden i en struct
- [ ] Lägga till knapp för att välja framåt eller bakåt
- [ ] Implementera funktion för servo motor i main programmet
- [ ] Hitta ett sätt att kunna läsa in bilder/texter för att sedan översätta och skriva ut dem med CNC maskinen
- [ ] Bygga en ställning för hela maskinen


## Pinnar som används:

| PORT | Beskrivning |
| :--- | :--- |
| PC0 | H-BRYGGA för stepper motor 1 (2A) |
| PC1 | H-BRYGGA för stepper motor 1 (3A) |
| PC2 | H-BRYGGA för stepper motor 1 (1A) |
| PC3 | H-BRYGGA för stepper motor 1 (4A) |
| PC4 | |
| PC5 | |
| PB0 | H-BRYGGA för stepper motor 2 (2A) |
| PB1 | H-BRYGGA för stepper motor 2 (3A) |
| PB2 | H-BRYGGA för stepper motor 2 (1A) |
| PB3 | H-BRYGGA för stepper motor 2 (4A) |
| PB4 | |
| PB5 | |
| PD0 | |
| PD1 | |
| PD2 | |
| PD3 | |
| PD4 | |
| PD5 | |
| PD6 | |
| PD7 | |
| VCC | H-BRYGGA FÖR STEPPER MOTOR 1 (12EN, VCC1, 34EN) |
| VCC | H-BRYGGA FÖR STEPPER MOTOR 2 (12EN, VCC1, 34EN) |
| GND | H-BRYGGA FÖR STEPPER MOTOR 1 (GND x4) |
| GND | H-BRYGGA FÖR STEPPER MOTOR 2 (GND x4) |

## Hårdvara
- [Nema 17](http://reprap.org/wiki/NEMA_17_Stepper_motor)
- [SN754410](http://www.ti.com/lit/ds/symlink/sn754410.pdf)
- [Atmega 328p](http://www.atmel.com/images/Atmel-8271-8-bit-AVR-Microcontroller-ATmega48A-48PA-88A-88PA-168A-168PA-328-328P_datasheet_Complete.pdf)

##### Andra användbara länkar
[How do I pass an IO port as a parameter to a function?](http://www.atmel.com/webdoc/avrlibcreferencemanual/FAQ_1faq_port_pass.html)
