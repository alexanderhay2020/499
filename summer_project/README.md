# 499 - Winter Project

## Timeline of Project
<p>
    <center><img src="/assets/schedule.png" width="100%;" height="100%;" alt/></center>
</p>

## Scope

The goal of this project was to explore the use of shape memory alloys (SMA) to mimic human movement using equilibrium point control (EPC). One of the tenets of EPC is motion control via "reciprocal-commands"<sup>[[1]](https://www.ncbi.nlm.nih.gov/pubmed/15136283?dopt=Abstract)[[2]](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC2342993/)</sup>, motor commands that change the muscle stiffness and cause the limb to move. The scope of this project explores using the alpha-model of EPC to control and actuate the SMA actuators.

## Apparatus

### Actuator
For this project I've chosen the Miga T220 SMA linear actuator. Actuation parallels human muscle; the Nitinol wire contracts when a current is passed through, just as muscles contract when activated by a neuron. Each actuator has a fan installed to increase how quickly the wire could relax. The T220 also has an onboard MOSFET switching and protection circuit, which cuts power to SMA wire when the output stage reached the End-of-Stroke contact.

<p>
    <img src="/assets/miga.jpg" width="50%;" height="50%;" alt/><img src="/assets/circuit_mosfet.png" width="50%;" height="50%;" alt/>
    <br>
    <em>left: Miga T220 SMA Linear Actuator, right: power protection circuit</em>
</p>

### Design

I choose the following design parameters for the project:

* Apparatus has a max length of 369mm<sup>[3]</sup>
* Minimum range of motion of 45 degrees
* Tricep, bicep, and branchialis muscles must be modeled
* Equilibrium point control model

The max length was determined as the average length of a male arm, measured from the shoulder to the elbow. The range of motion was a compromise between human ability (~150 degrees) and the mechanics of the system. Since the actuator has a very short throw they needed to be anchored to the "elbow" at very small distances to achieve any decent range of motion. To achieve 90 degrees the anchor point would need a radius of 4mm. For reference, a 1/4" shaft is 6.35mm (radius 3.175mm).

<p>
    <img src="/assets/chart1.png" width="70%;" height="70%;" alt/>
    <br>
    <em>chart shows relation between range of motion and actuator anchor distance</em>
</p>

Originally the project was to include modeling of all the major muscles in the arm; tricep, bicep, and brachialis. This was scraped towards the end for the presentation at the Museum of Science and Industry, the primary reasons being actuation speed, performance, and complexity. Stacking actuators is also a concern due to the fact that the mounting holes are part of the circuit and require plastic hardware. Limiting to two actuators simplifies the overall design and allows the fans the blow across more surface area, allowing the Nitinol wires to cool faster increasing actuation rate.

Equilibrium point control is an intuitive method of motor control proposed by Feldman, with the λ-model published in 1986. Motion of the joint is instigated by the reciprocal command, "which alters the relative activation of agonist and antagonist muscles to produce a shift in the equilibrium between the muscle force and external load"<sup>[[2]](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC2342993/)</sup> While falling out of favor somewhat recently it still provides a means by which motion control can be achieved.

### Assembly
Solidworks was used for modeling and assembly. .stl files can be found [here](https://drive.google.com/drive/folders/16_4EUu6pd2tG_H0EAVOFKAJVKnEg8ENC?usp=sharing). The frame is made from six (6) pieces made from acrylic or plywood.

1/4" bearings were press fit into the holes after a bit of sanding. Fans are mounted to their respective sides, making sure the fan pushed air over the actuator. Likewise, the actuators were screwed into the middle bracket using plastic spacers.

<p>
    <center><img src="/assets/assembly.gif" width="50%;" height="50%;" alt/>
    <br>
    <em>Apparatus exploded view</em></center>
</p>


A 1/4" shaft was placed through the bearings with two (2) collars placed on the shaft, one on the outside of each bearing bracket. Another collar was placed in the center, between the bearing brackets. 3D printed hollow screws were connected to the actuators and collars with a high strength nylon filament. A turnbuckle mechanism was used to maintain tension in the system. The apparatus is only designed to work in tension reflecting how our own muscles are structured.

The Ultimaker3 3D printer was used to make the shaft collars and the special screws needed for the turnbuckle assembly. A full BOM can be found [here](https://docs.google.com/spreadsheets/d/1KzUj851-XKCJ2QYp6Q05hCkz7jHLwCAjlV-5XQmAJzQ/edit?usp=sharing)

<p>
    <img src="/assets/img01.jpg" width="80%;" height="80%;" alt/>
    <br>
    <em>Complete assembly of project</em>
</p>

### Electronics
An Arduino UNO was used to interface with the actuators and fans. The actuators require analog/PWM pins, the fans require digital I/O pins.

Each actuator operates nominally at 9v at 0.3A<sup>[[4]](http://www.migamotors.com/Media/Miga-T220-Data-Sheet-102218.pdf)</sup>. Each fan requires 5v 0.2A. The UNO requires 5.5v to operate drawing minimal current. A 9V 2A power supply was used to power the components.

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

## Future work

The project as presented demonstrates an α-model method of motor control through changing the Nitinol wire properties. λ-model requires a feedback signal from the muscle spindle, a fiber running the length of the muscle that senses stretch sensory information. A λ-model could be modeled by installing a position sensor on the actuator or a rotary encoder at the joint, sending the muscle property data that the muscle spindle broadcasts. A PID controller could then be implemented to give the actuators a spring-like quality that is seen in muscle fibers<sup>[[5]](https://www.ncbi.nlm.nih.gov/pubmed/8930238)</sup>.

## References

[1] Anatol G. Feldman (1986) Once More on the Equilibrium-Point Hypothesis (λ Model) for Motor Control, Journal of Motor Behavior, 18:1, 17-54, DOI: 10.1080/00222895.1986.10735369

[2] Hinder, Mark R, and Theodore E Milner. “The case for an internal dynamics model versus equilibrium point control in human movement.” The Journal of physiology vol. 549,Pt 3 (2003): 953-63. doi:10.1113/jphysiol.2002.033845

[3] Gordon, Claire & Churchill, Thomas & Clauser, Charles & Bradtmiller, Bruce & McConville, John & Tebbetts, Ilse & Walker, Robert. (1989). Anthropometric Survey of U.S. Army Personnel: Summary Statistics, Interim Report for 1988.

[4] “Miga T220 Data Sheet.” Miga Motor Company, Silverton, OR, 22 Oct. 2018.

[5] Gribble PL, Ostry DJ. Origins of the power law relation between movement velocity and curvature: modeling the effects of muscle mechanics and limb dynamics. J Neurophysiol. 1996 Nov;76(5):2853-60. doi: 10.1152/jn.1996.76.5.2853. PubMed PMID: 8930238.
