# 🔐 PASSGENERATOR - Generador de Contraseñas Seguras

![PassGenerator](https://img.shields.io/badge/Security-High-green.svg) ![License](https://img.shields.io/badge/License-MIT-blue.svg)

## 🚀 Descripción
PASSGENERATOR es un potente generador de contraseñas aleatorias seguras, diseñado para su uso en criptografía y seguridad digital. Con este programa, puedes generar contraseñas robustas, únicas y altamente configurables.

## 📌 Características
✅ Generación de contraseñas aleatorias con una longitud configurable.
✅ Asegura que las contraseñas generadas sean únicas.
✅ Personalización del conjunto de caracteres (letras, números y caracteres especiales).
✅ Interfaz en consola intuitiva y fácil de usar.
✅ Compatible con Windows.

## 🛠️ Tecnologías Utilizadas
- Lenguaje: **C**
- API de Windows
- Consola de comandos

---

## 📥 Instalación
Para comenzar a usar PASSGENERATOR, sigue estos pasos:

### 1️⃣ Clonar el repositorio:
```bash
git clone https://github.com/harelo12/passgenerator.git
```

### 2️⃣ Compilación:
Si usas **MinGW**, ejecuta:
```bash
gcc main.c -o passgenerator.exe
```
Si usas **Visual Studio**, abre el proyecto y compílalo directamente desde el IDE.

### 3️⃣ Ejecución:
Ejecuta el programa desde la terminal con:
```bash
./passgenerator.exe
```

---

## 🖥️ Uso
Cuando ejecutes PASSGENERATOR, el programa generará una contraseña aleatoria y te preguntará si deseas generar otra.

Ejemplo de salida:
```bash
Contraseña generada: j9!Mn6^lP3#K
Desea repetir (S/n)?
```

Opciones:
- **S**: Generar una nueva contraseña.
- **n**: Salir del programa.

---

## ⚙️ Personalización
Puedes modificar la configuración predeterminada de PASSGENERATOR:
- **Longitud de la contraseña**: Cambiando el valor de `PASSWORD_LENGTH`.
- **Caracteres permitidos**: Editando el conjunto `CHARSET`.

Ejemplo de personalización en el código:
```c
#define PASSWORD_LENGTH 16 // Longitud de la contraseña
const char CHARSET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
```

---

## 🛠️ Contribuciones
💡 Se aceptan mejoras en:
- Seguridad del generador de contraseñas.
- Nuevas funcionalidades.
- Mejoras en la interfaz de usuario.

Si deseas contribuir, abre un **issue** o envía un **pull request**. 🚀

---

## 📜 Licencia
Este proyecto está bajo la **Licencia MIT**. Consulta el archivo LICENSE para más detalles.

---

### 👤 Autor
Creado por: **harelo12**
Fecha de creación: **13 de febrero de 2025**

