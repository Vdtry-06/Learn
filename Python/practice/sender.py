# Tạo file sender.py
import base64
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives import hashes, serialization

# Đọc khóa công khai
with open('public_key.pem', 'rb') as f:
    public_key = serialization.load_pem_public_key(f.read())

# Thông điệp cần mã hóa
message = "Thông điệp bí mật từ người gửi"
message_bytes = message.encode('utf-8')

# Mã hóa thông điệp
ciphertext = public_key.encrypt(
    message_bytes,
    padding.OAEP(
        mgf=padding.MGF1(algorithm=hashes.SHA256()),
        algorithm=hashes.SHA256(),
        label=None
    )
)

# Lưu thông điệp đã mã hóa
with open('encrypted.bin', 'wb') as f:
    f.write(ciphertext)

print("Đã mã hóa thông điệp và lưu vào encrypted.bin")