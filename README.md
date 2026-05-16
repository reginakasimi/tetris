
UML Sınıf Diyagramları (Önce / Sonra)

1. Önce (Faz 0 - İlk Durum)
`main.cpp` oyun döngüsü, tüm somut figür sınıflarına doğrudan bağımlıydı (Tight Coupling).

```mermaid
classDiagram
    class Main {
        +main()
        +randomShapes()
    }
    class Lshape {
        +initializeShapeMatrix()
    }
    class Ishape {
        +initializeShapeMatrix()
    }
    class Tshape {
        +initializeShapeMatrix()
    }
    class Jshape {
        +initializeShapeMatrix()
    }

    Main ..> Lshape : Dogrudan Bagimli
    Main ..> Ishape : Dogrudan Bagimli
    Main ..> Tshape : Dogrudan Bagimli
    Main ..> Jshape : Dogrudan Bagimli
