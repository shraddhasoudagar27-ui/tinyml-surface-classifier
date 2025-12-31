// --- Smart Surface Classifier (TinyML Inference on ESP32) ---
#define SENSOR_AO_PIN 33
#define STATUS_LED_PIN 2

float filteredValue = 0;
const float alpha = 0.2;

// Logistic Regression parameters
float coef[3] = {-0.15960338, 0.01869537, 0.14090801};
float intercept[3] = {339.44569239, 4.73136422, -344.17705661};

void setup() {
  Serial.begin(115200);
  pinMode(SENSOR_AO_PIN, INPUT);
  pinMode(STATUS_LED_PIN, OUTPUT);

  Serial.println("TinyML Surface Classifier Initialized!");
}

int predictClass(float x) {
  float scores[3];

  for (int i = 0; i < 3; i++) {
    scores[i] = coef[i] * x + intercept[i];
  }

  // Choose highest score as predicted class
  int bestClass = 0;
  for (int i = 1; i < 3; i++) {
    if (scores[i] > scores[bestClass]) {
      bestClass = i;
    }
  }
  return bestClass;
}

void loop() {
  int raw = analogRead(SENSOR_AO_PIN);
  filteredValue = alpha * raw + (1 - alpha) * filteredValue;

  int cls = predictClass(filteredValue);

  Serial.print("Intensity: ");
  Serial.print(filteredValue);
  Serial.print(" → Class: ");

  if (cls == 0) {
    Serial.println("Dark Surface");
    digitalWrite(STATUS_LED_PIN, LOW);
  } else if (cls == 1) {
    Serial.println("White Surface");
    digitalWrite(STATUS_LED_PIN, HIGH);
  } else if (cls == 2) {
    Serial.println("Reflective Surface");
    digitalWrite(STATUS_LED_PIN, HIGH);
  }

  delay(300);
}
