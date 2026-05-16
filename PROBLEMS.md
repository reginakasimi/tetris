FAZ0
Ben şu problemleri gördüm:

1. Kod Tekrarı: Her şekil içinde hareket fonksiyonları tamamen aynı.
2. Genişletme Zorluğu: Yeni bir şekil eklemek için yeni dosyalar oluşturmak ve mevcut kodun birçok yerini değiştirmek gerekiyor.
3. Main Sınıfına Bağımlılık: Tüm oyun mantığı sadece main fonksiyonu içinde bulunuyor.
4. Soyutlama Eksikliği: Shape arayüzü yerine doğrudan özel şekil sınıflarıyla (Lshape, Jshape vb.) çalışılıyor.
5. Tek Sorumluluk Prensibi İhlali: Bir sınıf; çizim, çarpışma kontrolü ve mantık gibi çok fazla görevi aynı anda yapıyor.

AI şu problemleri gördü:

Kod Tekrarı (Code Duplication): moveLeft, moveRight ve çarpışma kontrolleri gibi fonksiyonlar tüm sınıflarda (I, J, L vb.) birebir aynı şekilde yazılmış. Bu durum, kodun yönetilmesini zorlaştırır.
Aşırı Yüklü Sınıflar (God Class): Şekil sınıfları hem koordinat verilerini tutuyor, hem kullanıcı girişini (scanf) işliyor, hem de ekrana çizim yapıyor. Bu durum "Tek Sorumluluk Prensibi"ne (Single Responsibility) aykırıdır.
Esnek Olmayan Dönme Mantığı: Şekillerin dönme durumları switch-case ve next++ yapısıyla sınıfların içine sabitlenmiş (hardcoded). Yeni bir dönme açısı eklemek tüm sınıfı değiştirmeyi gerektirir.
Sıkı Bağlılık (Tight Coupling): Giriş alma ve oyun alanı matrisine (matrix[20][10]) doğrudan erişim, şekil sınıflarını oyunun diğer parçalarına çok bağımlı hale getiriyor.
Statik Veri Yapıları: prevMatrix gibi yapılarda dizilerin boyutları (3x3, 4x4) önceden belirlenmiş. Bu, farklı boyutlarda şekiller eklemeyi zorlaştırır.

AI başka problemleri da gördü. Ama çoğu sorunlar benim söylediğim gibi oldu.


FAZ1
Ben Creational Factory design pattern kullandım. Class'taki fonksiyonlar artık tekrar etmiyor. 1. problemi çözdüm.
