AES-128-Qt
This repository contains the implementation of the AES-128 encryption algorithm integrated with a Qt-based GUI. This application allows users to encrypt and decrypt text using a 128-bit AES key. Both operations require the key and the plaintext/ciphertext to be exactly 16 characters long.

How to Run
To run the application, please follow these steps:

Prerequisites
Ensure you have the Qt runtime libraries installed if they are not bundled with the release.

Running the Application
Navigate to Releases:

Go to Releases on the AES-128-Qt repository.
Download:

Download the latest release.zip file.
Extract:

Extract the contents of the zip file to your preferred location.
Execute:

Run AES.exe from the extracted files to start the application.
Usage
Once the application is running:

Encryption: Enter a 16-character long plaintext and a 16-character long key. Click the "Encrypt" button to encrypt the text.
Decryption: Enter a 16-character long ciphertext and use the same 16-character long key used for encryption. Click the "Decrypt" button to decrypt the text.
Important Note
Both the plaintext for encryption and the key must be exactly 16 characters long to ensure correct functioning of the AES-128 algorithm.

Building from Source
If you prefer to build the application from source:

Clone the Repository:
bash
Copy code
git clone https://github.com/ZeddHp/AES-128-Qt.git
Open the Project:
Open the project in Qt Creator.
Build the Project:
Configure the project using Qt Creator and build it.
Run:
Run the application directly from Qt Creator or from the build output directory.
Contributing
Contributions to the project are welcome. You can contribute by:

Reporting issues
Suggesting enhancements
Submitting pull requests with improvements
