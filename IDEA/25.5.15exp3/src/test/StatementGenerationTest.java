package test;
import org.junit.jupiter.api.Test;
import 拓展.*;

import static org.junit.jupiter.api.Assertions.assertAll;
import static org.junit.jupiter.api.Assertions.assertTrue;

class StatementGenerationTest {

    @Test
    void statement_contains_correct_details() {
        Customer customer = new Customer("Alice");
        customer.addRental(new  Rental(MovieFactory.createRegularMovie("Matrix"),  2));
        customer.addRental(new  Rental(MovieFactory.createNewReleaseMovie("Inception"),  3));

        String statement = customer.statement();

        assertAll(
            () -> assertTrue(statement.contains("Matrix")),
            () -> assertTrue(statement.contains("Inception")),
            () -> assertTrue(statement.contains("Amount  owed is")),
            () -> assertTrue(statement.contains("frequent  renter points"))
        );
    }

    @Test
    void htmlStatement_has_valid_format() {
        Customer customer = new Customer("Bob");
        customer.addRental(new  Rental(MovieFactory.createChildrenMovie("Frozen"),  4));

        String html = customer.htmlStatement();

        assertAll(
            () -> assertTrue(html.startsWith("<h1>")),
            () -> assertTrue(html.contains("<li>Frozen")),
            () -> assertTrue(html.contains("<em>"))
        );
    }
}