<?php

$csv = array_map('str_getcsv', file('results.csv'));
$numbers = array();

// Count the frequency of each number in the prior results
foreach ($csv as $row) {
    for($i = 0; $i < 6; $i++){
        if($i < 5){
            if (isset($numbers[$row[$i]]) && $row[$i] >= 1 && $row[$i] <= 70) {
                $numbers[$row[$i]]++;
            } else {
                $numbers[$row[$i]] = 1;
            }
        }else {
            if (isset($numbers[$row[$i]]) && $row[$i] >= 1 && $row[$i] <= 25) {
                $numbers[$row[$i]]++;
            } else {
                $numbers[$row[$i]] = 1;
            }
        }
    }
}

// Sort the numbers by frequency
arsort($numbers);

// Select the top 6 numbers
$predictedNumbers = array_slice(array_keys($numbers), 0, 6);

// Print the predicted numbers
print_r($predictedNumbers);

?>
