## UML Sınıf Diyagramları (Önce / Sonra)

### 1. Önce (Faz 0 - İlk Durum)

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

### 2. Sonra (Faz 1 - Factory Method Sonrası)

```mermaid
classDiagram
    class Main {
        +main()
    }
    class Factory {
        +randomShapes()
    }
    class Shape {
        <<abstract>>
        +input()
        +moveDown()
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

    Main ..> Factory : Nesne Talep Eder
    Factory ..> Shape : Uretir
    Lshape --|> Shape : Miras Alir
    Ishape --|> Shape : Miras Alir
    Tshape --|> Shape : Miras Alir
    Main ..> Shape : Sadece Arayuzu Kullanir
