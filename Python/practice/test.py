from Crypto.Cipher import Blowfish
import Crypto.Util.Padding

key = b"examplekey"  # Khóa đối xứng
cipher = Blowfish.new(key, Blowfish.MODE_CBC)

# Mã hóa
plaintext = b"This is a test message"
ciphertext = cipher.encrypt(pad(plaintext, Blowfish.block_size))

# Giải mã
decipher = Blowfish.new(key, Blowfish.MODE_CBC, iv=cipher.iv)
decrypted = unpad(decipher.decrypt(ciphertext), Blowfish.block_size)

print(f"Ciphertext: {ciphertext}")
print(f"Decrypted: {decrypted}")
