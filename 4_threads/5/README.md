## th.5: Parking model: thread-safe version

Starting from the outcome of exercise c.5, modify the class `PaymentParking` in
order to be thread-safe (i.e., allow multiple "car" threads to access the
parking without race conditions on the data).

Moreover, the `park()` member must be changed as follows: if the parking is
full, the car must wait for a slot to be freed. Once a free slot is available,
the car can proceed with the parking. We assume the parking has one only
entrance, so the cars can enter one per time, while we may have multiple cars
looking for a free slot in the area.

Implement a simple program showing the usage of the class, with multiple
threads simulating the cars entering the parking, staying there for a while and
then leaving.

