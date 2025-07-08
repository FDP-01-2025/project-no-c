[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)
# Proyecto de C++ - Tonacatale

## Descripción del Proyecto

Un pequeño juego inspirado en deltarune y undertale!

**Por ejemplo:**
Este proyecto consiste en un juego de aventuras donde el jugador debe explorar un mundo virtual, recoger objetos, resolver acertijos y enfrentar enemigos. El juego utiliza estructuras de control como `if`, `switch`, y bucles `while` y `for` para generar interacciones dinámicas.

## Equipo

- **Nombre del equipo:** No C + + 

### Integrantes del equipo

1. **Nombre completo:** William Enrique Hernandez Rodriguez  
   **Carnet:** 00095725

2. **Nombre completo:** Johann Andre Angel Menjivar  
   **Carnet:** 00071625

3. **Nombre completo:**   Daniel Alexander Avelar Orellana
   **Carnet:** 00089625

4. **Nombre completo:**  Jose Andres Calles Ramirez
   **Carnet:**  00054525

## Instrucciones de Ejecución

Para ejecutar Toncatale, unicamente debes abrir el .exe con administrador! //Es normal que windows lo trate como un virus pero es seguro, puedes comprobarlo viendo el codigo
Cuando inicie el juego no cambies el tamaño de la ventana, si lo haces el juego se bugueara graficamente y lo mejor seria reiniciarlo!

1. Clona este repositorio en tu máquina local:
   ```bash
   git clone https://github.com/FDP-01-2025/project-no-c.git
2. Si quieres actualizar y o cambiar el codigo, para compilar como requisito se debe tener una version de mingw superior a las 8
3. Para compilar pon en la termina: g++ main.cpp -lwinmm y presiona enter y listo!

- Temática y ambientación 
El juego se desarrolla en un ambiente oscuro el cual el jugador despierta en una ciudad prácticamente desierta llamada Tonacatale en el cual el jugador tiene que buscar la forma de salir vivo de ahí enfrentadose a enemigos fuertes, el jugador tiene que derrotarlos, subir de nivel, coleccionar ítems, explorar las salas hasta llegar al jefe final que es el más fuerte del juego
- Idea general de la jugabilidad
El jugador se mueve con las teclas WASD, juego 2D, te mueves entre salas/cuartos, 
 - Aplicación de los temas vistos (uno por uno con ejemplos) 
If (Si el jugador intenta pasarse de la coordenada delimitada, se imprimirá la coordenada anterior para no permitir que se pase de los limites)
![image](https://github.com/user-attachments/assets/1b117706-7bcb-4328-a879-3616e1efe411)

Else (Al solicitar mostrar los saves guardados previamente, si no hay ninguno guardado mandar mensaje de error porque no se ha creado el archivo adonde se han guardado los saves)

![image](https://github.com/user-attachments/assets/0f2bd3dd-f477-4c5b-acb0-04c5267b42eb)

Switch (Dependiendo de la tecla que se presione el jugador hará una acción, siendo el WASD de movimiento, la Q y E siendo de utilidad) 

![image](https://github.com/user-attachments/assets/9e2f1045-3386-4d16-997b-d2435df75f4f)

For (Se usa para dibujar los bordes o cosas que aparecerán en el mapa)
Ej. Se dibuja un rio usando el carácter ■ 

![image](https://github.com/user-attachments/assets/f6d5629a-84d3-4d9a-8777-38c7c5b0e06b)

While (Se usa para dibujar los bordes de los cuadros de texto)
Ej. Se dibuja la línea horizontal de un cuadro de texto

![image](https://github.com/user-attachments/assets/5a0cbfe6-29a1-4c40-9c6b-b53a8c3840d7)

Funciones (Se crean las funciones voids para no tener que repetir el código varias veces cuando la función sea necesitada)
Ej. Show_chest se usara para mostrar el cofre en otra parte del código, lo hacemos mas corto para cuando necesitemos poner ese cofre solo tenga que ser llamada la funcion Show_chest

![image](https://github.com/user-attachments/assets/68bd2ceb-9040-419d-ba79-658494b324e0)

Manejo de archivos (Uso de Ofstream e Ifstream, Ofstream siendo para abrir y escribir en dicho archivo, Ifstream siendo para abrir y Leer el archivo, estas usan el manejo de archivos <fstream> (abreviado“File stream”))
Ej. manejo de archivos para guardar y leer los saves del juego.

![image](https://github.com/user-attachments/assets/0828a906-d640-4b38-8679-b21862714f6b)
![image](https://github.com/user-attachments/assets/21ebd494-d3d1-40b8-828c-370febad498e)

  
- Consideraciones técnicas del desarrollo
- El juego fue desarrollado en Lenguaje C++
- Compatible con Windows 10 y 11
- (siempre y cuando tener MingW actualizado a la ultima version)
- Se priorizo la jugabilidad, sistema de combate e items del juego
- Para el audio se utilizó la biblioteca mmsystem.h (Windows Multimedia API), que permite reproducir sonidos en formato WAV    de forma sencilla.

- Imágenes o mockups del juego

![image](https://github.com/user-attachments/assets/30ccf27b-2c42-463c-8650-b525ad7f50ad)
![image](https://github.com/user-attachments/assets/e0303bc0-d02a-49bd-ad2c-7afe5b857517)
![image](https://github.com/user-attachments/assets/5af96d14-a437-4416-b30a-6893b0890fd3)
![image](https://github.com/user-attachments/assets/4a28c1fc-f7b7-4a98-84d9-bc44a1bd2f6b)
![image](https://github.com/user-attachments/assets/74b496f8-f569-449b-be71-1afc704a59a5)
![image](https://github.com/user-attachments/assets/f2a0651e-9492-484a-b9ab-bfd5fefc2ff4)
