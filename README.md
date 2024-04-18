# HTTP-GET

# ESP32 Random Joke Fetcher

This Arduino sketch demonstrates how to connect an ESP32 microcontroller to a Wi-Fi network, make an HTTP GET request to fetch a random joke from a public API, parse the JSON response, and display the joke on the serial monitor.

## Prerequisites

- Arduino IDE installed on your computer.
- ESP32 board selected and configured in the Arduino IDE.
- `WiFi` and `HTTPClient` libraries installed in Arduino IDE.

## Setup Instructions

1. **Configure Wi-Fi Credentials**:
   - Open the Arduino sketch (`random_joke_fetcher.ino`).
   - Replace `"AirFiber"` and `"Hnasetty09"` with your Wi-Fi network SSID and password in the `ssid` and `password` variables.

2. **Upload Sketch to ESP32**:
   - Connect your ESP32 board to your computer via USB.
   - Select the correct board and port in Arduino IDE.
   - Click the **Upload** button to upload the sketch to your ESP32 board.

3. **Open Serial Monitor**:
   - Once the sketch is uploaded, open the serial monitor in Arduino IDE (`Tools > Serial Monitor`).
   - Set the baud rate to `115200` to view the output.

4. **View Random Joke**:
   - After connecting to Wi-Fi and initializing, the ESP32 will fetch a random joke from the API.
   - The joke setup and punchline will be displayed on the serial monitor.

## Code Explanation

### `setup()`

- Initializes serial communication and connects the ESP32 to the specified Wi-Fi network.
- Calls the `fetchRandomJoke()` function to fetch and display a random joke.

### `fetchRandomJoke()`

- Uses the `HTTPClient` library to make an HTTP GET request to the joke API (`https://official-joke-api.appspot.com/random_joke`).
- Checks the HTTP response code:
  - If successful (`HTTP_CODE_OK`), it reads the JSON response, parses it to extract the joke setup and punchline, and displays the joke on the serial monitor.
  - If unsuccessful, it prints an error message indicating the failure to fetch the joke.

### `extractJokeFromJson()`

- Parses the JSON response to extract the joke setup and punchline using string manipulation (`indexOf()` and `substring()` functions).
- Assumes the JSON response format is `{ "setup": "...", "punchline": "..." }`.

## Troubleshooting

- If the sketch fails to connect to Wi-Fi, verify the SSID and password.
- Check the serial monitor for debug messages and error notifications.
- Ensure that the ESP32 is correctly configured and connected to your computer.

## Notes

- This example uses simple string manipulation to parse the JSON response. For more robust JSON parsing, consider using a JSON parsing library like `ArduinoJson`.
- Explore different APIs and endpoints to fetch various types of data and integrate them into your Arduino projects.

