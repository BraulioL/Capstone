import serial
import tkinter as tk
from tkinter import ttk
import threading

# === Serial Configuration ===
SERIAL_PORT = 'COM3' 
BAUD_RATE = 9600

# === Serial Reader Thread ===
def read_serial():
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()
            print(line)  # Debug print
            if "Soil moisture" in line:
                moisture_label.config(text=line)
            elif "Pump" in line:
                pump_label.config(text=line)

# === GUI Setup ===
root = tk.Tk()
root.title("Soil Moisture Monitor")
root.geometry("400x200")
root.configure(bg="#f4f4f4")

style = ttk.Style()
style.configure("TLabel", font=("Helvetica", 14))

moisture_label = ttk.Label(root, text="Soil moisture: ---", foreground="green")
moisture_label.pack(pady=20)

pump_label = ttk.Label(root, text="Pump status: ---", foreground="blue")
pump_label.pack(pady=10)

# === Start Serial and Thread ===
try:
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
    threading.Thread(target=read_serial, daemon=True).start()
except serial.SerialException:
    print(f"Could not open serial port {SERIAL_PORT}")
    moisture_label.config(text="Serial Error!")
    pump_label.config(text="Check connection")

root.mainloop()
