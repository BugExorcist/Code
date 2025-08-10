package test;

import org.junit.jupiter.api.Test;
import 拓展.*;

import static org.hamcrest.MatcherAssert.assertThat;
import static org.junit.jupiter.api.Assertions.*;

class RentalCalculationTest {

    // 测试数据准备
    private final Movie regularMovie = MovieFactory.createRegularMovie("The  Godfather");
    private final Movie childrenMovie = MovieFactory.createChildrenMovie("Toy  Story");
    private final Movie newReleaseMovie = MovieFactory.createNewReleaseMovie("Avatar  2");
    private final Movie documentaryMovie = MovieFactory.createDocumentaryMovie("Planet  Earth");

    @Test
    void regularMovie_pricing_rules() {
        Rental rental1 = new Rental(regularMovie, 1);
        Rental rental3 = new Rental(regularMovie, 3);

        assertAll(
            () -> assertEquals(2.0, rental1.getCharge()),  // ≤2天收2元
            () -> assertEquals(3.5, rental3.getCharge())   // 超出部分每天1.5元
        );
    }

    @Test
    void newRelease_points_rules() {
        assertAll(
            () -> assertEquals(1, new Rental(newReleaseMovie, 1).getFrequentRenterPoints()),
            () -> assertEquals(2, new Rental(newReleaseMovie, 2).getFrequentRenterPoints())
        );
    }

    @Test
    void documentary_special_pricing() {
        Rental rental = new Rental(documentaryMovie, 4);
        assertThat(rental.getCharge()).isEqualTo(4  * 1.2); // 纪录片每天1.2元
    }
}