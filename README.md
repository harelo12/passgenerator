
# 🔐 **PASSGENERATOR** - Generador de Contraseñas Seguras

![PassGenerator](https://img.shields.io/badge/Security-High-green.svg) ![License](https://img.shields.io/badge/License-MIT-blue.svg)
***
> [!NOTE]
> 
Instalador de la aplicación lista para usar: [Click Aquí](https://www.mediafire.com/file/fkf438smacuhd3p/setup-passgenerator.exe/file) (Solo sirve para Windows)
***
## 🚀 **Descripción**
**PASSGENERATOR** es una herramienta diseñada para generar contraseñas seguras y aleatorias, asegurando alta protección para tus cuentas en línea. El generador es totalmente configurable y permite crear contraseñas únicas con un conjunto personalizado de caracteres. Además, guarda automáticamente las contraseñas generadas en un archivo si así lo deseas.

## 📌 **Características**
- ✅ **Generación de contraseñas aleatorias** con longitud configurable.
- ✅ **Garantiza contraseñas únicas** para evitar repeticiones.
- ✅ **Personalización de caracteres** (letras, números, símbolos especiales).
- ✅ **Interfaz de usuario amigable** en consola.
- ✅ **Guardar contraseñas** generadas en un archivo de texto.
- ✅ Compatible con **Windows**.

## 🛠️ **Tecnologías Utilizadas**
- Lenguaje: **C**
- API de **Windows**
- Consola de **Comandos**

---

## 📥 **Instalación**
Para comenzar a usar **PASSGENERATOR**, sigue estos pasos:

### 1️⃣ **Clonar el repositorio**:
```bash
git clone https://github.com/harelo12/passgenerator.git
```

### 2️⃣ **Compilación**:
Si usas **MinGW**, ejecuta:
```bash
gcc main.c -o passgenerator.exe
```
Si usas **Visual Studio**, abre el proyecto y compílalo directamente desde el IDE.

### 3️⃣ **Ejecutar el programa**:
Ejecuta el programa desde la terminal con:
```bash
./passgenerator.exe
```

---

## 🖥️ **Uso**
Cuando ejecutes **PASSGENERATOR**, el programa generará una contraseña aleatoria. Después, te preguntará si deseas generar otra contraseña o guardarla en un archivo.

**Ejemplo de salida**:
```bash
Contraseña generada: j9!Mn6^lP3#K
¿Deseas repetir (S/n)?
```

**Opciones**:
- **S**: Generar una nueva contraseña.
- **n**: Salir del programa.

---

## ⚙️ **Personalización**
Puedes modificar la configuración predeterminada de **PASSGENERATOR** editando las siguientes constantes en el código:

- **Longitud de la contraseña**: Cambia el valor de `PASSWORD_LENGTH`.
- **Caracteres permitidos**: Edita el conjunto `CHARSET`.

**Ejemplo de personalización en el código**:
```c
#define PASSWORD_LENGTH 16 // Longitud de la contraseña
const char CHARSET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
```

---

## 🛠️ **Funciones principales**
**PASSGENERATOR** incluye varias funciones de utilidad para mejorar el control sobre las contraseñas generadas.

- `generate_password`: Genera una contraseña aleatoria de longitud configurada.
- `is_unique_password`: Verifica que la contraseña generada sea única entre las anteriores.
- `savePass`: Guarda las contraseñas generadas en un archivo de texto `passlist.txt`.
- `mainfunc`: Controla la lógica del programa, incluyendo la opción de guardar contraseñas y repetir el proceso.

---

## 🧑‍💻 **Contribuciones**
💡 Se aceptan mejoras en:
- Seguridad del generador de contraseñas.
- Nuevas funcionalidades.
- Mejoras en la interfaz de usuario.

Si deseas contribuir, abre un **issue** o envía un **pull request**. 🚀

---

## 📜 **Licencia**
Este proyecto está bajo la **Licencia MIT**. Consulta el archivo `LICENSE` para más detalles.

---

### 👤 **Autor**
- **Creado por**: **harelo12**
- **Fecha de creación**: **13 de febrero de 2025**
