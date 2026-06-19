# Rescate de Atahualpa

Trabajo Final de Algoritmos (2026-01). Juego 2D en **C++/CLI (Windows Forms)** donde
**Cusi** debe recorrer tres niveles (costa, altiplano y selva), recolectar objetos
culturales, esquivar a los soldados y al Capitán español, y apoyarse en sus aliados
para avanzar en el rescate de Atahualpa.

## Requisitos

- Visual Studio 2026 (o VS2022)
- Toolset de plataforma **v143**
- .NET Framework **4.8**

## Cómo abrir y compilar

1. Abrir `TrabajoFinalAlgoritmos.slnx` en Visual Studio.
2. Seleccionar configuración `Debug | x64`.
3. Compilar y ejecutar (F5).

## Estructura

```
TrabajoFinalAlgoritmos/
├── Formularios/   FormGeneral (menú), FormControlJuego (base) y FormNivel1..3
├── Personajes/    Entidad → Personaje → Cusi / Enemigo (+ subclases) / Aliado (+ subclases) / ObjetoCultural
├── Juego/         Juego, Nivel, Ranking
└── Enums/         Direccion, EjePatrulla, EstadoJuego
```

> Estado actual: esqueleto de clases generado a partir del diagrama UML. La lógica de
> cada método está pendiente (marcada con `// anadir logica`).
