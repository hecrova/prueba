## Motivación del Proyecto

¿Qué sucede cuando combinamos la Navidad con una galaxia muy, muy lejana? 
Imagina un belén navideño que cobra vida con luces sincronizadas, melodías épicas y tecnología avanzada, inspirado en el universo de *Star Wars*.  
Este proyecto  es el trabajo final del Bloque VI del Máster del Profesorado, impartido por el profesor José Antonio Aveleira.

El objetivo es crear algo más que una decoración: es una experiencia interactiva que sorprende y despierta curiosidad a los más pequeños de la casa. Nuestro portal de Belén se transforma en un escenario donde la innovación y la creatividad son los protagonistas.

## Objetivos del Proyecto

1. **Diseñar una experiencia interactiva:** Crear un belén navideño temático de *Star Wars*, que combine luces y música sincronizadas con la tecnología de sensores infrarrojos para capturar la atención y la imaginación.  
2. **Desarollar la creatividad tecnológica:** Programar un microcontrolador ESP32 para ejecutar secuencias dinámicas que integren LEDs, un buzzer y control remoto, mostrando la potencia de la tecnología aplicada al arte y el entretenimiento.  
3. **Impulsar la creatividad artística:** Incorporar elementos decorativos únicos mediante impresión 3D y materiales personalizados, creando un ambiente que mezcla tradición navideña y ciencia ficción.  
4. **Compartir:** Documentar el proyecto, haciéndolo accesible a la comunidad a través de GitHub, para inspirar a otros a replicar o reinventar esta idea.  

Este belén no solo celebra la Navidad, sino que también muestra cómo la tecnología puede convertirse en una herramienta para contar historias y conectar mundos. 


## Características del Proyecto

- **Control de LEDs:** Iluminación sincronizada de LEDs durante la reproducción de melodías.
- **Reproducción de música:** Interpretación de canciones famosas como *Star Wars* y la *Marcha Imperial* usando un buzzer.
- **Interacción IR:** Uso de un receptor de infrarrojos para detectar comandos desde un control remoto.
- **Componentes integrados:**
  - LEDs conectados a diferentes pines digitales.
  - Buzzer para generar sonidos musicales.
  - Receptor IR compatible con la librería `DIYables_IRcontroller`.

## Funcionalidades del Código

### Configuración Inicial (`setup`)
- Configura los pines de los LEDs como salida.
- Inicializa el buzzer y el receptor IR.
- Prepara la comunicación serie para depuración.

### Secuencias de Operación
1. **Reproducción de melodías:** 
   - Las canciones se representan como arreglos de notas y duraciones.
   - Los LEDs se iluminan y apagan de forma sincronizada con las notas.
2. **Apagado de LEDs:** 
   - Función dedicada para asegurar que todos los LEDs estén apagados al finalizar una secuencia.
3. **Control IR:**
   - Detecta la presión del botón `1` en el control remoto para activar las secuencias musicales y visuales.

### Ciclo Principal (`loop`)
- Escucha continuamente comandos del control remoto.
- Al presionar el botón `1`, ejecuta la función `performSequence`:
  - Enciende un LED inicial.
  - Reproduce la canción de *Star Wars* con LEDs asignados.
  - Tras una pausa, reproduce la *Marcha Imperial* con un conjunto diferente de LEDs.
  - Apaga todos los LEDs al finalizar.

## Requisitos del Hardware

1. **Microcontrolador:** Placa compatible con Arduino.
2. **LEDs:** 7 LEDs conectados a los pines especificados.
3. **Buzzer:** Conectado al pin 15.
4. **Receptor IR:** Compatible con la librería `DIYables_IRcontroller`.
5. **Control Remoto IR:** Para enviar comandos al receptor.

## Librerías Utilizadas

- **`Arduino.h`**: Librería base para programación de Arduino.
- **`DIYables_IRcontroller.h`**: Manejo del receptor infrarrojo y decodificación de comandos.

## Instalación y Uso

1. **Montaje de Hardware:**
   - Conecte los LEDs, el buzzer y el receptor IR a los pines especificados.
   - Verifique las conexiones de tierra y alimentación.

2. **Carga del Código:**
   - Abra el archivo en el IDE de Arduino.
   - Seleccione el puerto y la placa correspondientes.
   - Compile y cargue el código en la placa.

3. **Uso del Control Remoto:**
   - Presione el botón `1` para iniciar la secuencia de melodías y efectos de luces.

## Expansión

- Personalice las melodías agregando nuevos arreglos de notas.
- Modifique la configuración de LEDs para diferentes patrones de iluminación.
- Integre nuevos comandos del control remoto para añadir funcionalidades.

## Autor

Este proyecto fue desarrollado para demostrar la integración de control de LEDs, reproducción musical y comunicación IR en un sistema Arduino.

## Licencia

Este proyecto está disponible bajo la [Licencia MIT](LICENSE). Consulte el archivo de licencia para más detalles.

