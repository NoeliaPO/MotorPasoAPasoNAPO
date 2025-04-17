# MotorPasoAPasoNAPO
# 🚀 Control de Motor Paso a Paso con Arduino Nano

**Facultad de Ciencias y Tecnología - Universidad San Francisco Xavier de Chuquisaca (USFX)**
**Noelia Alejandra Párraga Ortuzte**  
**Ingeniería en Telecomunicaciones**  

---

Este proyecto permite controlar un motor paso a paso **Nema 17 bipolar** mediante comandos seriales utilizando un **Arduino Nano** y un controlador **L298N**, empleando la librería `Stepper.h`.

---

## 📦 Componentes Utilizados

- Arduino Nano  
- Motor Nema 17 (bipolar, 200 pasos/rev)  
- Módulo puente H L298N  
- Fuente de alimentación externa (para el motor)  
- Cables de conexión  
- Software: Arduino IDE  

---

## ⚙️ Descripción del Proyecto

El sistema permite controlar el giro del motor paso a paso en intervalos de 90°, representando posiciones de 0°, 90°, 180° y 270°. También se puede realizar rotaciones completas, ajustar velocidad de rotación y ejecutar secuencias automáticas horarias y antihorarias.

### 🔧 Funcionalidades principales:

- Movimiento entre posiciones fijas  
- Control de dirección de giro  
- Reinicio a posición 0°  
- Rotación de 360°  
- Cambio dinámico de velocidad por comandos  
- Modo automático de secuencias  

---

## 🔌 Conexión de Pines

### 🧾 Diagrama de Conexión (Texto)

| Componente         | Conexiones     | Conecta a Arduino | Nota                             |
|--------------------|----------------|-------------------|----------------------------------|
| Bobina A (Nema 17) | IN1, IN3 (L298N)| D8, D10           | Conectadas en orden de fase      |
| Bobina B (Nema 17) | IN2, IN4 (L298N)| D9, D11           | Conectadas en orden de fase      |
| ENA / ENB          | -              | Activar con puente| Puentes soldados o jumper activo |
| GND                | -              | GND               | Compartido con Arduino           |
| VCC Motor          | -              | Fuente externa    | Según voltaje del motor          |

---

## 💻 Diagrama de Conexión

<p align="center">
  <img src="assets/Diagrama.png" alt="Diagrama de conexión" width="500"/>
</p>

---

## 🛠️ Montaje en Laboratorio

<p align="center">
  <img src="assets/Montaje.png" alt="Montaje físico" width="400"/>
  <br><br>
  <img src="assets/Armado.png" alt="Vista del armado" width="400"/>
</p>

---

## 🔁 Funcionamiento del Sistema

<p align="center">
  <img src="assets/Funcionamiento.gif" alt="Funcionamiento del motor" width="500"/>
</p>

---

## 🧪 Comandos Seriales Disponibles

| Comando | Descripción                            |
|---------|----------------------------------------|
| `F`     | Avanza 90° (posición siguiente)        |
| `D`     | Retrocede 90° (posición anterior)      |
| `S`     | Regresa a posición 0°                  |
| `0–3`   | Mueve a una posición específica        |
| `R`     | Gira 360° completos                    |
| `V###`  | Cambia la velocidad (ej: `V120`)       |
| `P`     | Muestra la posición actual             |
| `A`     | Ejecuta una secuencia automática horaria    |
| `B`     | Ejecuta una secuencia automática antihoraria|

