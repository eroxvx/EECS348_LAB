<!DOCTYPE html>
<html>
<body>

<form method="post" action="">
  <label for="inputNumber">Enter the number:</label><br>
  <input type="number" id="inputNumber" name="inputNumber" min="1" required><br>
  <input type="submit" value="submit">
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $inputNum = $_POST['inputNumber'];

    echo "<table border='1'>";
    echo "<thead><tr><td>*</td>";
    for ($col = 1; $col <= $inputNum; $col++) {
        echo "<td>$col</td>";
    }
    echo "</tr></thead>";

    for ($row = 1; $row <= $inputNum; $row++) {
        echo "<tr><th>$row</th>";
        for ($col = 1; $col <= $inputNum; $col++) {
            echo "<td>" . ($row * $col) . "</td>";
        }
        echo "</tr>";
    }
    echo "</table>";
}
?>

</body>
</html>
