# 499 - Winter Project

## Timeline of Project
<p>
    <center><img src="/assets/schedule.png" width="100%;" height="100%;" alt/></center>
</p>

## Scope

The goal of this project was to explore the use of shape memory alloys (SMA) to mimic human movement using equilibrium point control (EPC). One of the tenets of EPC is motion control via "reciprocal-commands"<sup>[[1]](https://www.ncbi.nlm.nih.gov/pubmed/15136283?dopt=Abstract)[[2]](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC2342993/)</sup>, motor commands that change the muscle stiffness and cause the limb to move. The scope of this project explores using the alpha-model of EPC to control and actuate the SMA actuators.

## Apparatus

### Actuator
The Miga T220 SMA linear actuator was chosen for this project. Other considerations included servo motors, magnetic actuators, belt/gear mechanical actuators, pneumatic systems, and other SMA actuators. Form, power, and hardware interface were the driving deciding factors. A decision matrix can be found [here](https://docs.google.com/spreadsheets/d/1p3fjq4K-Gl2H-Soi13WV8KOYeHxsrkHLGmXQxgn4opM/edit?usp=sharing)

<p>
    <center><img src="/assets/miga.jpg" width="50%;" height="50%;" alt/>
    <br>
    <em>Miga T220 SMA Linear Actuator</em></center>
</p>

### Assembly
Solidworks was used for modeling and assembly. .stl files can be found [here](https://drive.google.com/drive/folders/16_4EUu6pd2tG_H0EAVOFKAJVKnEg8ENC?usp=sharing). The frame is made from six (6) pieces made from acrylic or plywood.

1/4" bearings were press fit into the holes after a bit of sanding. Fans are mounted to their respective sides, making sure the fan pushed air over the actuator. Likewise, the actuators were screwed into the middle bracket using plastic spacers.

<p>
    <center><img src="/assets/assembly.gif" width="50%;" height="50%;" alt/>
    <br>
    <em>Apparatus exploded view</em></center>
</p>


A 1/4" shaft was placed through the bearings with two (2) collars placed on the shaft, one on the outside of each bearing bracket. Another collar was placed in the center, between the bearing brackets. 3D printed screws were connected to the actuators and collars with a high strength nylon filament. A turnbuckle mechanism was used to maintain tension in the system. The apparatus is only designed to work in tension reflecting how our own muscles are structured.

The Ultimaker3 3D printer was used to make the shaft collars and the special screws needed for the turnbuckle assembly. A full BOM can be found [here](url)

### Electronics
An Arduino UNO was used to interface with the actuators and fans. The actuators require analog/PWM pins, the fans require digital I/O pins.

Each actuator operates nominally at 9v<sup>[[3]](http://www.migamotors.com/Media/Miga-T220-Data-Sheet-102218.pdf)</sup> at 0.3A. Each fan requires 5v 0.2A. The UNO requires 5.5v to operate drawing minimal current. A 9V 2A power supply was used to power the components.

## Code

A structure was created to link the actuator and opposite fan; controlling the opposite fan (ie. sending an activation signal to the "tricep" actuator and "bicep" fan) because the speed of actuation depends on the cooling rate of the Nitinol wire.

```
typedef struct {
  int fanPin;
  int actPin;
} Muscle;
```

Functions flex() and relax(), requiring the Muscle struct.
```
void flex(Muscle m){
  analogWrite(m.actPin, 1023);
  digitalWrtie(m.fanPin, HIGH)
}

void relax(Muscle m){
 analogWrite(m.actPin, 0);
 digitalWrite(m.fanPin, LOW);
}
```

Because the wires require some amount of time to cool, a delay is inserted.
```
flex(tricep);
relax(bicep);
delay(5000);
```
## References

[1] Anatol G. Feldman (1986) Once More on the Equilibrium-Point Hypothesis (λ Model) for Motor Control, Journal of Motor Behavior, 18:1, 17-54, DOI: 10.1080/00222895.1986.10735369

[2] Hinder, Mark R, and Theodore E Milner. “The case for an internal dynamics model versus equilibrium point control in human movement.” The Journal of physiology vol. 549,Pt 3 (2003): 953-63. doi:10.1113/jphysiol.2002.033845

[3] “Miga T220 Data Sheet.” Miga Motor Company, Silverton, OR, 22 Oct. 2018.

[4] Gribble PL, Ostry DJ. Origins of the power law relation between movement velocity and curvature: modeling the effects of muscle mechanics and limb dynamics. J Neurophysiol. 1996 Nov;76(5):2853-60. doi: 10.1152/jn.1996.76.5.2853. PubMed PMID: 8930238.
