Documentación para GitHub:
Proyecto: PASSGENERATOR
Descripción:
Generador de contraseñas aleatorias válidas para criptografía.

Creado por: harelo12
Fecha de creación: 13 de febrero de 2025

Objetivo:
Este proyecto tiene como objetivo generar contraseñas aleatorias y seguras que pueden ser utilizadas en aplicaciones de criptografía. El programa permite al usuario generar múltiples contraseñas y asegura que no se repitan.

Características:

Generación de contraseñas aleatorias con una longitud configurable.
Se asegura de que las contraseñas generadas sean únicas.
Personalización del conjunto de caracteres (incluyendo caracteres especiales, letras y números).
Interfaz en consola fácil de usar con opciones para repetir la generación de contraseñas.
Instrucciones de Uso:
Clona el repositorio:

bash
Copiar
Editar
git clone https://github.com/harelo12/passgenerator.git
Compilación: Para compilar este proyecto, se requiere un compilador compatible con C y la API de Windows (como MinGW o Visual Studio). Si usas Visual Studio, abre el proyecto desde allí y compílalo directamente.

Ejecución: Al ejecutar el programa, este generará una contraseña aleatoria y la mostrará en la consola. Luego, te pedirá si deseas generar una nueva. Si decides continuar, el programa generará una nueva contraseña asegurándose de que sea única.

Ejemplo de salida:

bash
Copiar
Editar
Contraseña generada: j9!Mn6^lP3#K
Desea repetir (S/n)?
Opciones:

S: Generar una nueva contraseña.
n: Salir del programa.
Personalización:

Puedes modificar la longitud de la contraseña cambiando el valor de PASSWORD_LENGTH.
Puedes añadir más caracteres al conjunto CHARSET para incluir caracteres especiales adicionales si es necesario.
Contribuciones:
Bugs: Si encuentras algún error o mejora en el programa, no dudes en abrir un "issue" o realizar un "pull request".
Mejoras: Se aceptan contribuciones para mejorar la seguridad de la generación de contraseñas, agregar nuevas funcionalidades o mejorar la interfaz de usuario.
Licencia:
Este proyecto está bajo la Licencia MIT. Consulta el archivo LICENSE para más detalles.
