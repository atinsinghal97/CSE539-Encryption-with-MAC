# encryption-with-MAC

**Objective: Write a program that encrypts data using symmetric encryption and MAC**

**Technology Requirements**
- C on Linux (gcc)


**Project Description**

- A message authentication code (MAC) is a short piece of information that confirms when a message came from the stated sender and has not been changed. A MAC protects data integrity and authenticity as verifiers can detect any changes to the message content.

- HMAC, or hash-based message authentication code,  is a popular system of checking message integrity. The HMAC algorithm uses one-way hash functions to produce unique MAC values. HMACs can be keyed or non-keyed. HMAC does not encrypt the message. Instead, the message (encrypted or not) must be sent alongside the HMAC hash. If the message is authentic, the received and computed hashes will match.

- In this project, you will write programs to encrypt and decrypt data using symmetric encryption and MAC. For encryption, use the 32-bit encryption program from Brute Forcing and Cryptanalysis project. For hashing, use the 32-bit hash function from the Rainbow Table Attack project.


**Directions**

1. Write a program to compute a MAC. Your program should use the following approach: MAC = H(key | E(message)) where H is the 32-bit hash function from the Rainbow Table Attack project and E is the 32-bit encrypt function from the Brute Force and Cryptanalysis project. Note that the original 32-bit encrypt function adds an additional 4 bytes of data to the beginning of the file (the size of the file). You must modify the encrypt so that it does not add additional bytes (i.e. a 1024-byte input should produce a 1024-byte output).

2. Modify your program to work with command line inputs. There will be two inputs. First, it will receive the path to the file containing the 1024 bytes that need a MAC generated. It will also receive the key with which to perform the encryption and MAC generation. You can test your program on a 1024-byte file you create or on the file included here.
