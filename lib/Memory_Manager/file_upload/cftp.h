// design structs describing a packet,
// design a flow chart for the state machines
// File name, checksum, moddate
#define START_TRANS 1 // set the legitimate states to 1..n, success to 0, and
#define CONTINUE_TRANS 2
#define READ_PACKET 3
#define NO_ERROR 0
#define NORMAL_EXIT 0
#define CHECKSUM -1; // a check sum error
#define PACKET_CHECK_INTERVAL 50
#define TIME_OUT -2;
#define ERROR -1 // the error state
#define PACKET_TIMEOUT 1000;
#define DEFAULT_PACKET_SIZE 32
#define MAX_ALLOWED_TIME_OUTS 3

struct header;

struct header
{
	unsigned char ack_info;
	unsigned char packet_number_low;
	unsigned char packets_remaining;
	unsigned char length_file_name;

	unsigned int check_sum;

}

struct packet
{
	unsigned char header[8];
	unsigned char buffer[128 - sizeof(header)]; // Dangerous sizeof used for padding!!!!
	unsigned char contents[128];
}; // packets interpret headers...
// This keeps track of what files to read etc.

class Receiver
{
	unsigned char in_buffer[];
	unsigned char packet_number;
	unsigned char control_buffer[sizeof(header)];
	// unsigned int total_size; // Potentially useful
	unsigned char state;
	int time_since_start;

public:
	bool check_time();
	void clear()
	{
		while (Serial.available())
			Serial.read();
	}
	int receive()
	{

		int packet_number = 0;
		int packet_wait_time = 0;
		int number_of_time_outs = 0;
		// delay(WAIT_TIME);
		int packet_size = DEFAULT_PACKET_SIZE;
		Serial.flush();
		while (Serial.available())
			Serial.read();
		state = START_TRANS;
		int error = NO_ERROR;

		while (state > 0)
		{
			switch (state)
			{
			case CONTINUE_TRANS:
				if (Serial.available() >= packet_size)
				{
					state = READ_PACKET;
				}
				else if (packet_wait_time > PACKET_TIMEOUT)
				{
					error = TIME_OUT;
					state = error;
					number_of_time_outs++;
				}
				else
				{
					state = CONTINUE_TRANS;
				}
				delay(PACKET_CHECK_INTERVAL);
				packet_wait_time = packet_wait_time + PACKET_CHECK_INTERVAL;

				break;
			case READ_PACKET:
				// time = 0; // If you received a packet; the time is reset.
				// load_packet();

				// packet_info = check_packet();
				// if (packet_info !=0){
				error = CHECKSUM;
				state = ERROR:
			}
			// ack(SUCCESS); // ?
			// save_packet();
			if (packet.remaining = 0)
			{
				state = 0;
				return 0; // There are no more packets and they were all read successfully.
			}
			else
			{
				state = CONTINUE_TRANS;
			}
			break;
		case ERROR:
			if (error == CHECKSUM)
			{
				// There shoud be a way to totally reset the thing at any time.
				if (hard_reset_check(packet))
				{
					// delete the file
					// return HARD_RESET;
				}
				request_resend();
				state = CONTINUE_TRANS;
			}
			else if (error == TIME_OUT)
			{
				if (number_of_time_outs < MAX_ALLOWED_TIME_OUTS)
				{
					error = 0;
					state = 0;
				}
				return TIME_OUT;
			}
			else if (error ==)
				break;
		}
	}

} class Packet
{

public:
	Packet make_packet(String packet_info)
	{
		Packet newPacket
	}
}

class cftp_bot
{
	unsigned char status;		// ready, disabled etc? // probably will delete this
	unsigned char state;		// state in the mealy machine
	unsigned char remote_state; // the two machines will probably be identical but start in different states
	unsigned char in_buffer[];	// fed to packet class for interpretation
	unsigned char out_buffer[];
	unsigned char content_buffer[]; // Filled up with content and then flushed to file / larger block
	// unsigned char large_buffer[]; // Largest files could benefit from 4096 sized block;
	Receiver receiver;

	String cur_file;
	unsigned char current_packet;
	unsigned char current_window;
	int length_content; // Total file length;
	// int refresh_rate; // again. should probably have a way to modify these state variables.
	// int baud_rate; // Probably should have a way to modify this..
	int epoch_time;

public:
	// 7. App layer: human accessible. Program accessible in this case, i.e. sending files? Maybe these are the public functions.
	// 6. Presentation layer, usable formate, data encryption. Data conversion to class understandable form?
	// 5. Session Layer; responsible for controlling ports and sessions.
	// 4. Transport layer: Transmits data using tcp/ip prototcols and controls data transmission.
	int receive_file(String file_name);
	int request_files(); // All files?
	int start_session(int number_check, int delay_between_checks)
	{
		while (Serial.available())
			Serial.read();
		Serial.flush();
		unsigned char in;
		unsigned char syn_number = 0;
		for (int i = 0; i < number_check; i++)
		{
			in = Serial.read();
			if (in == syn_number) // Syn number was alreay incremented in the previous step
			{
				unsigned int ack = Serial.read();
				Serial.write(ack);
				return NORMAL_EXIT; // sent, received, ack
			}
			Serial.write(syn_number);
			syn_number++;
			delay(delay_between_checks);
		}
		return ERROR; // Basic error, value -1
	}				  // Set up connection, confirm data rate etc.
					  // int send_file();

	int read_header()
	{
	}
	int initialize_dir()
	{

		if (start_session() < 0)
		{
			return ERROR;
		}
		char a = '#';
		char b = '#';
		char c = '#';
		char d = '#';
		char temp_d;
		while (true)
		{
			if ((a == '#') && (b == 'E') && (c == 'N') && (d == 'D'))
			{
				Serial.write(0);
				return 0;
			}
			a = b;
			b = c;
			c = d;
			temp_d = Serial.read();

			read_header()

				while if (header != exit)
			{
				read_body;
			}
			// read_body()
		}

		return NORMAL_EXIT;
	}
	// is present?
}