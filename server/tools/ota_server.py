
#!/usr/bin/env python3
import socket, struct, threading
HOST, PORT = "127.0.0.1", 50051
def send_meta(conn, vin="VIN12345678901234", target=3, version="0.0.0", total_size=1024, crc32=0xDEADBEEF):
    vinb = vin.encode()[:17].ljust(18, b"\x00"); ver = version.encode()[:15].ljust(16, b"\x00")
    pkt = struct.pack("!B18sB16sII", 0x01, vinb, target, ver, total_size, crc32)
    conn.sendall(pkt)
def send_chunk(conn, offset, payload):
    pkt = struct.pack("!BIH", 0x02, offset, len(payload)) + payload
    conn.sendall(pkt)
def handle_client(conn, addr):
    print(f"[SERVER] client {addr}")
    try:
        send_meta(conn)
        for i in range(4): send_chunk(conn, i*256, b"\x00"*256)
        conn.sendall(b"\x03")
    finally: conn.close()
def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1); s.bind((HOST, PORT)); s.listen(1)
        print(f"[SERVER] listening on {HOST}:{PORT}")
        while True:
            conn, addr = s.accept()
            threading.Thread(target=handle_client, args=(conn, addr), daemon=True).start()
if __name__ == "__main__": main()

