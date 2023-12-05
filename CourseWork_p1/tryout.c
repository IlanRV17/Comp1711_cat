while (fgets(line, buffer_size, input))
            {

            // split up the line and store it in the right place
            // using the & operator to pass in a pointer to the bloodIron so it stores it
                tokeniseRecord(line, ",", daily_readings[counter].date, daily_readings[counter].time, this_is_a_string);

                daily_readings[counter].steps = atoi(this_is_a_string);
            
                counter++;
            }

            while ((ch = fgetc(filename)) != EOF) {
            if (ch == '\n') {
                record_counter++; 
                }
            }

           fseek(filename, 0, SEEK_SET);
                