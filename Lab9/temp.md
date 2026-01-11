### Treść:
Przeanalizuj, czy z punktu widzenia marketingowego producentowi Coca-Coli bardziej opłaca się zwiększyć promień puszki, czy też jej wysokość. W reklamie ma się pojawić komunikat o "większej objętości puszki" (wskazówka: różniczka funkcji dwóch zmiennych). Rozwiązanie powinno zawierać wszystkie obliczenia i konkluzje (Markdown)

### Rozbicie problemu:
Analizujemy na co pujdzie mniej materiału zwiększenie wysokości czy promienia na by zwiększyć objętości puszki o $\Delta V$.

### Wzory i onliczenia:
Puszka jest walcem. Pole powierzchni potrzebne na wykonanie puszki opisujemy wzorem 
$$
P = 2r\pi(H + r)
$$
a objętość puszki opisujemy wzorem 
$$
V = r^{2} H \pi
$$
gdzie $H$ - to wysokość puszki a $r$ - to promieć podstawy.
Zakładamy że V jest z góry ustalona przez producenta to znaczy że na przykład podjeli decyzjie że zwiększą pojemność o 0.25l co za tym idzie $\Delta V = 0.25$. Z tego checmy ustalić o ile sie zmieni $P$.

---

Liczymy $\Delta V$.
$$
\Delta V = \frac{\Delta V}{\Delta r}\Delta r + \frac{\Delta V}{\Delta H}\Delta H 
$$
$$
V = r^{2}H\pi \implies \frac{\Delta V}{\Delta r} = 2rH\pi \implies \Delta V = 2rH\pi\Delta r
$$
$$
V = r^{2}H\pi \implies \frac{\Delta V}{\Delta H} = r^{2}\pi \implies \Delta V = r^{2}\pi\Delta H
$$
$$
\Delta V = 2rH\pi\Delta r + r^{2}\pi\Delta H
$$

Z tego otrzymujemy zmiane $\Delta V$ na podstawie orginalnych wymiarów $r$ i $H$ oraz zmainy $\Delta r$ i $\Delta H$

Sprawdzenie:
$$
r = 0.1 \land H = 0.5 \implies V = 0.005\pi
$$
$$
r = 0.1 \land H = 0.5 + 0.1 \implies V = 0.006\pi
$$
$$
\Delta V = 0.006\pi - 0.005\pi = 0.001\pi \land \Delta H = 0.1 \land \Delta r = 0 \implies \Delta V = 2rH\pi\Delta r + r^{2}\pi\Delta H = 2 \cdot 0.1 \cdot 0.5 \pi \cdot 0 + 0.1^{2} \pi \cdot 0.1 = 0 + 0.1^{2} \pi \cdot 0.1 = 0.001\pi
$$

Czyli:
$$
\Delta V = 2rH\pi\Delta r + r^{2}\pi\Delta H
$$
Jest wzorem na różnice objętości na podstawie różnicy $r$ i $H$

---

Robimy to samo dla $P$:
$$
\Delta P = \frac{\Delta P}{\Delta r}\Delta r + \frac{\Delta P}{\Delta H}\Delta H 
$$
$$
P = 2r\pi(H + r) = 2rH\pi + 2r^{2}\pi \implies \frac{\Delta P}{\Delta r} = 2H\pi + 4r\pi \implies \Delta P = (2H\pi + 4r\pi)\Delta r
$$
$$
P = 2r\pi(H + r) = 2rH\pi + 2r^{2}\pi \implies \frac{\Delta P}{\Delta H} = 2r\pi \implies \Delta P = 2r\pi\Delta H
$$

Sprawdzenie:
$$
r = 0.1 \land H = 0.5 \implies P = 2r\pi(H + r) = 2 \cdot 0.1(0.1 + 0.5)\pi = 0.12\pi
$$
$$
r = 0.1 \land H = 0.5 + 0.1 \implies P = 2r\pi(H + r) = 2 \cdot 0.1(0.1 + 0.6)\pi = 0.14\pi
$$
$$
\Delta P = 0.14\pi - 0.12\pi = 0.02\pi \land \Delta H = 0.1 \land \Delta r = 0 \implies \Delta P = (2H\pi + 4r\pi)\Delta r + 2r\pi\Delta H = 2r\pi\Delta H = 2 \cdot 0.1\pi \cdot 0.1 = 0.02\pi
$$

---

Na podstawie:
$$
\Delta P = (2H\pi + 4r\pi)\Delta r + 2r\pi\Delta H
$$
$$
\Delta V = 2rH\pi\Delta r + r^{2}\pi\Delta H
$$

Możemy wywnioskować co sie bardziej opłaca zwiększyć by oszczędzić przy okazji materiał po przez analize współczynników przy $\Delta H$ i $\Delta r$ w $\Delta P$:

$$
\Delta r = \frac{\Delta V - r^{2}\pi\Delta H}{2rH\pi}
$$
$$
\Delta H = \frac{\Delta V - 2rH\pi\Delta r}{r^{2}\pi}
$$
$$
\frac{\Delta P}{\Delta r} = 2H\pi + 4r\pi > 2r\pi = \frac{\Delta P}{\Delta H}
$$
$$
(2r - H)\Delta V > - 4rH^{2}\pi\Delta r + (r^{2}H\pi + 2r^{3}\pi)\Delta H
$$











<!-- 
Mamy dwie funkcjie liniowe z różnymi współczynikami kierunkowymi $(H + 2r)2\pi$ dla $\Delta r$ i $2r\pi$ dla $\Delta H$
 -->



<!-- $$
H > -r, \Delta r \text{ rośnie szybciej niż } \Delta H 
$$
$$
H < -r, \Delta H \text{ rośnie szybciej niż } \Delta r
$$

I założenia że $r > 0$ i $H > 0$ mamy:
$$
H > -r, \text{Jest zawsze prawdą} 
$$
$$
H < -r, \text{Jest zawsze kłamstwem}
$$

Zatem opłaca nam sie zwiększać $\Delta H$ bo zawsze rośnie wolniej od $\Delta r$. -->



<!-- 
### Fajne zadanie
Dla zadanego $\Delta V$ wyliczyć najoptymalniejsze $\Delta r$ i $\Delta H$.


---
Mamy:
$$
\Delta P = (2H\pi + 4r\pi)\Delta r + 2r\pi\Delta H
$$
$$
\Delta V = 2rH\pi\Delta r + r^{2}\pi\Delta H
$$

Potrzenujemy znaleźć $\Delta P$ w zależności od $\Delta V$:

$$
\Delta P = (2H\pi + 4r\pi)\Delta r + 2r\pi\Delta H = 2H\pi\Delta r + 4r\pi\Delta r + 2r\pi\Delta H 
$$
$$
\Delta V = 2rH\pi\Delta r + r^{2}\pi\Delta H
$$
$$
\Delta r = \frac{\Delta V - r^{2}\pi\Delta H}{2rH\pi}
$$
$$
\Delta P = (2H\pi + 4r\pi)\frac{\Delta V - r^{2}\pi\Delta H}{2rH\pi} + 2r\pi\Delta H = \frac{\Delta V - r^{2}\pi\Delta H}{r} + 2 \cdot \frac{\Delta V - r^{2}\pi\Delta H}{H} + 2r\pi\Delta H =
$$
$$
\frac{\Delta V}{r}  + \frac{2 \Delta V}{H} - \frac{2r^{2}\pi\Delta H}{H} + r\pi\Delta H = \frac{\Delta V}{r}  + \frac{2 \Delta V}{H} - \frac{2r - H}{H}r\pi\Delta H =
$$
$$
(\frac{1}{r} + \frac{2}{H})\Delta V - (\frac{2r}{H} - 1)r\pi\Delta H
$$
$$
\Delta P(\Delta V, \Delta H) = (\frac{1}{r} + \frac{2}{H})\Delta V - (\frac{2r}{H} - 1)r\pi\Delta H
$$

Gdzie $\Delta V$ jest stałą a $\Delta H$ jest zmienną.
$$
\Delta P(\Delta H) = (\frac{1}{r} + \frac{2}{H})\Delta V - (\frac{2r}{H} - 1)r\pi\Delta H
$$

Szukamy minimum
$$
(\frac{1}{r} + \frac{2}{H})\Delta V - (\frac{2r}{H} - 1)r\pi\Delta H = 0
$$
$$
\Delta H = \frac{(\frac{1}{r} + \frac{2}{H})\Delta V}{(\frac{2r}{H} - 1)r\pi}
$$

ma jedno miejsce zerowe roœne $\Delta H = \frac{(\frac{1}{r} + \frac{2}{H})\Delta V}{(\frac{2r}{H} - 1)r\pi}$ i jest funkcjią liniową. Z współczynnikiem kierunkowym róœnym $- (\frac{2r}{H} - 1)r\pi$ wiemy że $r > 0 \land H > 0$ by sprawdzić czy jest malejąca sprawdzamy warunek $- (\frac{2r}{H} - 1)r\pi < 0$ co za tym idzie $- \frac{2r}{H} + 1 < 0 \implies 2r > H$ dla takich $r$ i $H$ funkcjia ma minimum. I optrzymujemy najoptymalniejsze $\Delta H$.

na podstawie tego wyznaczamy $\Delta r$

Ostatecznie 
$$
\Delta H = \frac{(\frac{1}{r} + \frac{2}{H})\Delta V}{(\frac{2r}{H} - 1)r\pi}
\land
\Delta r = \frac{\Delta V - r^{2}\pi\frac{(\frac{1}{r} + \frac{2}{H})\Delta V}{(\frac{2r}{H} - 1)r\pi}}{2rH\pi}
\land 
2r > H
\land r > 0
\land H > 0
$$ -->
