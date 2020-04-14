# CSE539-Encryption-with-MAC

**Objective: Write a program that encrypts data using symmetric encryption and MAC**

**Technology Requirements**
- C on Linux (gcc)


**Project Description**

- A message authentication code (MAC) is a short piece of information that confirms when a message came from the stated sender and has not been changed. A MAC protects data integrity and authenticity as verifiers can detect any changes to the message content.

- HMAC, or hash-based message authentication code,  is a popular system of checking message integrity. The HMAC algorithm uses one-way hash functions to produce unique MAC values. HMACs can be keyed or non-keyed. HMAC does not encrypt the message. Instead, the message (encrypted or not) must be sent alongside the HMAC hash. If the message is authentic, the received and computed hashes will match.

- In this project, you will write programs to encrypt and decrypt data using symmetric encryption and MAC. For encryption, use the 32-bit encryption program from Brute Forcing and Cryptanalysis project. For hashing, use the 32-bit hash function from the Rainbow Table Attack project.
