#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "AirFiber";
const char* password = "Hnasetty09";

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Connect to Wi-Fi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Fetch a random joke
  //fetchRandomJoke();
}

void loop() {
  // Leave the loop empty since we're fetching jokes only once in setup()
  fetchRandomJoke();
  delay(10000);
}

void fetchRandomJoke() {
  // Make an HTTP GET request to fetch a random joke
  HTTPClient http;
  http.begin("https://official-joke-api.appspot.com/random_joke");

  int httpResponseCode = http.GET();
  if (httpResponseCode == HTTP_CODE_OK) {
    String jsonResponse = http.getString();
    Serial.println("Response: " + jsonResponse);

    // Parse JSON response to extract joke content
    String joke = extractJokeFromJson(jsonResponse);
    Serial.println("Random Joke:");
    Serial.println(joke);
  } else {
    Serial.println("Error: Failed to fetch joke");
  }

  http.end(); // Close connection
}

String extractJokeFromJson(String jsonResponse) {
  // Parse JSON response to extract joke content
  // Here we assume the response format is {"setup": "...", "punchline": "..."}
  String setup = "";
  String punchline = "";

  // Parse JSON using simple string manipulation (not recommended for complex JSON)
  int startIndex = jsonResponse.indexOf("\"setup\":") + 9;
  int endIndex = jsonResponse.indexOf("\",", startIndex);
  setup = jsonResponse.substring(startIndex, endIndex);

  startIndex = jsonResponse.indexOf("\"punchline\":") + 13;
  endIndex = jsonResponse.indexOf("\"}", startIndex);
  punchline = jsonResponse.substring(startIndex, endIndex);

  return setup + " " + punchline;
}
