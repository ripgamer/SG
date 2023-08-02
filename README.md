# Speed Monitoring System with ESP8266 and Blynk 🚗🚀

![Speed Monitoring System](https://lh3.googleusercontent.com/pw/AIL4fc_WZmPgVpkvJWhb5YOk1w4Ti9uRzFZUOn-9p6Ot0oAEqQk2hHEsWXdNRW4_cojOBhaXiDiItx0o6tKzcslzJEvz63xbMlqWt74Yfuw2HnCEznq7FfsUpeo1SS1A3tPnzj34EJKq19bbJhh_x-2vcbg0kCMedPdvFcsN6-cxbzdaT21IdE9bKneGdHDMEjU9udnRi1u1VAYD-8XizJJXxP0O0IC00hKAG3s4L9J4rQF5Jo5NWq2t_9U3mQvMksuLSVYwac0Wb45XAWLIna97XyvLCbxYs3Ipwy2FrrAeSkSZSWcAfcWuZRX_HZZoJBsDvFJ9Uv7JueqjbBftnoHI1PJpgcBZ2t-uyjrZqPbosPzooPwboWJktwMBnWpWVgfkSJiOS9cmAC0Ze1kF69k5v5nPFOfcPtuw1E8H9RIunT1ojcDsSiiXY_1ziL38XhQms7PWUmG7TamY_tF-sWn_QiS6RMMM6nSZ-nng9MBV9xVw2BqahJhqu3WEH5sg4GwvJu45m15mkHDmtYW0FobDI2Pkall5chXZJD7j7Ka0-4Z3M2NUw1G54FQGb1Ohm7A7afuJ3OOdxsTBD4rQv9-HT_yNoWfRFhQ5YK46-j5JnVEb5MnFfJ5GfPPEkwqyGnJRPk0kPZy-fas5qsBvYYhEs3IAMci7MAZ3tnzGUNJXnkrBT28lsHm4XNkp1C-RJnkQd_aUkXJOR5I8ANva9FOTXjjMflMB5LZHgTSaQWPvq578DUV3HxSgE1j8mvvIRIrmcJIsEegATrnnnZNN3pVbVxJbNGxi2RXhk93ryb3o39IJGBTtNaTUVrON5p0gVjliwYNVSdO21T-bcF0Z-MXd2ihrXS3OEEQ8eCaomCOhRs2_OT7hkQJiaw1yFu3EfBrz26z7sAmxFdrRvdMQB7ZkhupQMg=w157-h209-no?authuser=0)

This repository contains the Arduino sketch for a speed monitoring system using an ESP8266 module and Blynk IoT platform. The system measures the speed of passing vehicles using infrared sensors and displays the speed on an LCD display and a Blynk app gauge widget. It also notifies if a vehicle is over-speeding.

## Hardware Setup 🛠️

- ESP8266 module (like NodeMCU) with WiFi capabilities
- Infrared sensors (IR) connected to analog pins A0 and A1
- LCD display connected via I2C
- Buzzer connected to pin 13
- Two voltage control pins (vcc1 and vcc2) for powering the IR sensors

## Libraries Used 📚

- [ESP8266_Lib](insert_esp8266_lib_url_here)
- [BlynkSimpleShieldEsp8266](insert_blynk_lib_url_here)
- [LCD_I2C](insert_lcd_i2c_lib_url_here)

## Blynk Integration 📡

The speed value is displayed on a Blynk app gauge widget. To use this code, you need to set up a Blynk project and obtain the Blynk authentication token. Replace the placeholder `<ADD YOUR AUTH_TOKEN HERE>` in the code with your actual token.

## Speed Calculation ⏱️

The speed is calculated based on the time taken by a vehicle to pass between the two IR sensors, assuming a fixed distance of 4.5 meters between the sensors. The calculated speed is displayed on both the LCD display and the Blynk gauge.

## LCD Display 🖥️

The LCD display shows the calculated speed and status messages. If the speed is greater than 50 Km/Hr, it displays "Over Speeding" and activates the buzzer briefly. If the speed is within limits, it displays "Normal Speed."

## How to Use 🚀

1. Clone this repository to your local machine.
2. Install the required libraries in your Arduino IDE (ESP8266_Lib, BlynkSimpleShieldEsp8266, and LCD_I2C).
3. Open the `speed_monitoring_system.ino` file in your Arduino IDE.
4. Set your Wi-Fi credentials (SSID and password) in the sketch.
5. Replace `<ADD YOUR AUTH_TOKEN HERE>` with your actual Blynk authentication token.
6. Upload the sketch to your ESP8266 module.
7. Connect the hardware components as per the Hardware Setup section.
8. Power on the system and monitor the speed of passing vehicles.

## Project Images 📷
![Image 2](https://lh3.googleusercontent.com/pw/AIL4fc_cSJ-rHZorsNdEQeb0DuDEXvq-3Na3OU0OEtPbRbkuDqq7G1UwG0oqWIR9kORcFCBd7D7Wf9DK5gNKRfm6tqZzdnh-mOFsHWRwTmczsrsiH_jAX0-UoT7g4sP9NLoOdN6RBVgjrvAoPwYnDaQgHMHozF2plH43__YcMa91O5Yfc3hDVuyZHPkZiOWjeZt_UCymuxHVC2IB7Jf4U6KqL64WJVz_xelavdsFnOQteZqL2oSVKb76eiYfDldcqEm8sTX25ea1TTsxkTS3FLKCE2xaF0-EYxbiXcwfFt8yFroQjH4xqpe70pzFiHoMYjYcGWu-FeIOv4pfgB5Hso8_CKFZJL2iVQiGd6V1o9eUpLAJZgpdYn8eyEA0Db1Wu3EDo-ZB119o2xHu7ey4w6_eHqj4hE3m2sK_SP2V2pnX4wMaKGtemzUo9abvFRZ-Zu2_E2ksbdDW4fQ2hWvB12qEWIpuWArSXbqECK9lfuOoTxQ9VFyrj0mj2nHcBFyG3pVxuEN1_ejIq8jt9B85QZxpQ9afbCpHFlUrTgK8QJ9FbYrb1ZRFrMvoS0zaoO_wGzQ78WNRAM5tLgQQ7N65qY-HmAd7tEWiyHp6tZpnNeFquVk-IIbx87MbNsY-b8sMpBAJRWApWzS15hEKGIiWpaE_KK4e7sEsimz29_h4jLKTffwUQwPtRGN92d6U88jOJFdwKrj60SICN6n56jreo6Bb4dPsX1tbVZceSrmr5UYY1OjVx8VQErxUzWJ3OoFd79Y4i9ceXb726VsyKUQ5ataA_IqvUX4JEThASJvaOPtaUKm7Ur_gpOaTeRCgFG7JtjEf3TNQ2ectyFQcG9K5eImZ1u9Oqu0q6ZZ_oHW7oUJQGY7BY4yEWGN0_jux7oec2ok65JlNOxxScRRcOHJUy-keDkOQ7Q=w673-h894-s-no?authuser=0)

## License 📜

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments 🙏

Special thanks to the contributors of the libraries used in this project.

## Contact 📧

If you have any questions or suggestions, feel free to contact me:
- GitHub: [@ripgamer](https://github.com/ripgamer)
- Email: akashdeepkumar0001@gmail.com
  <p align="center">
    Made with :heart: by <a href="https://github.com/ripgamer">RipGamer</a> :rocket:
</p>
