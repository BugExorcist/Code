package test;

import org.junit.jupiter.api.Test;
import 拓展.*;

import static org.junit.jupiter.api.Assertions.assertAll;
import static org.junit.jupiter.api.Assertions.assertEquals;

class RentalsIntegrationTest {

    @Test
    void rentals_aggregation_works() {
        Rentals rentals = new Rentals();
        rentals.add(new  Rental(MovieFactory.createRegularMovie("R1"),  1));
        rentals.add(new  Rental(MovieFactory.createNewReleaseMovie("R2"),  2));

        assertAll(
            () -> assertEquals(2 + 2*3, rentals.getTotalAmount()),  // 2 + 6
            () -> assertEquals(1 + 2, rentals.getTotalPoints())      // 1 + 2
        );
    }
}
