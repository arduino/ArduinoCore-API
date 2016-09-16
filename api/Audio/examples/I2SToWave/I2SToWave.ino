#include <SPI.h>
#include <SD.h>

#include <ArduinoI2S.h>
#include <WaveFile.h>

// filename on SD card to read
const char filename = "test.wav";

// pin to use as input
const int buttonPin = 2;

// recording length in milliseconds
const int recordingTime = 30 * 1000;

File file;
WaveFile waveFile;

bool recordingInProgress = false;
unsigned long recordingStart;

void setup() {
  Serial.begin(9600);
  while (!Serial); // wait for serial port to connect. Needed for native USB port only

  // setup the button as an input
  pinMode(buttonPin, INPUT);

  // setup the SD card
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1); // do nothing
  }
  Serial.println("initialization done.");

  // start I2S, philips mode, 24-bits per sample, 16 kHz
  if (!I2S.begin(PHILIPS_MODE, 24, 16000) {
    Serial.println("error starting I2S");
    while(1); // do nothing
  }
}

void loop() {
  if (recordingInProgress) {
    // recoriding has already started, record a sample
    recordSample();
  } else if (digitalRead(buttonPin) == HIGH) {
    // no recording in process but button pressed, start recording
    startRecording();
  }
}

void recordSample() {
  // try to read a sample from the microphone
  uint32_t sample;

  if (I2S.readSample(sample)) {
    // write sample to wave file
    waveFile.writeSample(sample);
  }

  // check if we've recorded for long enough
  if ((millis() - recordingStart) > recordingTime) {
    // stop recording
    Serial.println("Stopping recording");

    I2S.receiveDisable();

    waveFile.endWrite();

    recordingInProgress = false;
  }
}

void startRecording() {
  Serial.print("Starting recording to ");
  Serial.println(filename);

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  file = SD.open(filename, FILE_WRITE);

  // check if the file opened sucessfully
  if (!file) {
    Serial.print("error opening ");
    Serial.println(filename);
    while (1); // do nothing
  }

  // use the file to create a WaveFile
  waveFile = WaveFile(file);

  if (!waveFile.beginWrite(24, 2, 16000)) {
    Serial.println("Starting Wave write failed");
    while (1); // do nothing
  }

  // enable receive mode
  I2S.receiveEnable();

  recordingInProgress = true;
}
