////////////////////////////////////////////////////////////////////////////////
//
//  File           : fs3_driver.c
//  Description    : This is the implementation of the standardized IO functions
//                   for used to access the FS3 storage system.
//
//   Author        : Yiling Mou
//   Last Modified : *** DATE ***
//

// Includes
#include <string.h>
#include <cmpsc311_log.h>
#include <stdbool.h>
#include <fs3_controller.h>

// Project Includes
#include <fs3_driver.h>

//
// Defines
#define SECTOR_INDEX_NUMBER(x) ((int)(x/FS3_SECTOR_SIZE))

//
// Static Global Variables

struct 
{
	int position;
	int length;
	bool fileOpen;
	int fileHandle;
	char fileName;


} fs3_fileHandle[FS3_MAX_TOTAL_FILES];




// create an FS3 array opcode from the variable fields

FS3CmdBlk construct_fs3_cmdblock(uint8_t op, uint16_t sec, 
uint_fast32_t trk, uint8_t ret)
{
	op = op << 60;                  // 4 bits set opcode
	sec = sec << 44;                // 16 bits set sector number
	trk = trk << 12;                // 32 bits set track number 
	ret = ret << 11;                // 1 bit set return value

	return ( op | sec | trk | ret );
} ;



// extract register state from bus values

int deconstruct_fs3_cmdblock(FS3CmdBlk cmdblock, uint8_t *op, 
uint16_t *sec, uint32_t *trk, uint8_t *ret)
{
	*op = cmdblock <<;
	*sec = cmdblock <<;
	*trk = cmdblock <<;
	*ret = cmdblock <<;
};



//
// Implementation

////////////////////////////////////////////////////////////////////////////////
//
// Function     : fs3_mount_disk
// Description  : FS3 interface, mount/initialize filesystem
//
// Inputs       : none
// Outputs      : 0 if successful, -1 if failure

int32_t fs3_mount_disk(void) {
	return(0);
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : fs3_unmount_disk
// Description  : FS3 interface, unmount the disk, close all files
//
// Inputs       : none
// Outputs      : 0 if successful, -1 if failure

int32_t fs3_unmount_disk(void) {
	return(0);
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : fs3_open
// Description  : This function opens the file and returns a file handle
//
// Inputs       : path - filename of the file to open
// Outputs      : file handle if successful, -1 if failure

int16_t fs3_open(char *path) 
{
	// check if file already open(fail if already open)
    // pick unique file handle
    // save filename and file information locally
    // set file pointer to first byte
    // if file not exists
    // set length to 0
    // return file handle

	return (0); // Likely wrong
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : fs3_close
// Description  : This function closes the file
//
// Inputs       : fd - the file descriptor
// Outputs      : 0 if successful, -1 if failure

int16_t fs3_close(int16_t fd) 
{
	while ( fd >= 0 && fd < FS3_MAX_TOTAL_FILES )
	{
		for ( int i = 0; i < FS3_MAX_TOTAL_FILES; i++)
		{
			if ( fs3_fileHandle[i].fileHandle = fd && fs3_fileHandle[i].fileOpen == true)
			{
				fs3_fileHandle[i].fileOpen == false;
				logMessage(FS3DriverLLevel, "success to CLOSE");
				return 0;
			}
		}
	}
	logMessage(LOG_ERROR_LEVEL, "fail to CLOSE");
	return -1;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : fs3_read
// Description  : Reads "count" bytes from the file handle "fh" into the 
//                buffer "buf"
//
// Inputs       : fd - filename of the file to read from
//                buf - pointer to buffer to read into
//                count - number of bytes to read
// Outputs      : bytes read if successful, -1 if failure

int32_t fs3_read(int16_t fd, void *buf, int32_t count) {

	int readByte;
	// check if file handle valid (is associated with open file)
	if ( fd >= 0 && fd < FS3_MAX_TOTAL_FILES && fs3_fileHandle[fd].fileOpen == true )
	{
		// check length to if it is valid
		if(( fs3_fileHandle[fd].position + count) <= fs3_fileHandle[fd].length)
		{
			readByte 
		}

	}

    // figure out what track/sector data for the read is
    // get the sector
    // copy the data from the sector to buffer
    // update the file pointer
    // return the number of read bytes

	return (0);
}


////////////////////////////////////////////////////////////////////////////////
//
// Function     : fs3_write
// Description  : Writes "count" bytes to the file handle "fh" from the 
//                buffer  "buf"
//
// Inputs       : fd - filename of the file to write to
//                buf - pointer to buffer to write from
//                count - number of bytes to write
// Outputs      : bytes written if successful, -1 if failure

int32_t fs3_write(int16_t fd, void *buf, int32_t count) 
{
	
	
	
	if (count <= 0 )
	{
		return -1;
	}
	else if ( fd <= -1 || fd >= FS3_MAX_TOTAL_FILES)
	{
		return -1;
	}



	return (0);

}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : fs3_seek
// Description  : Seek to specific point in the file
//
// Inputs       : fd - filename of the file to write to
//                loc - offfset of file in relation to beginning of file
// Outputs      : 0 if successful, -1 if failure

int32_t fs3_seek(int16_t fd, uint32_t loc) 
{
	if ( fd >= 0 && fd < FS3_MAX_TOTAL_FILES )
	{
		if ( fs3_fileHandle[fd].fileOpen == true && fs3_fileHandle[fd].length >= loc )
		{
			fs3_fileHandle[fd].position = loc;
			logMessage(FS3DriverLLevel, "success to SEEK");
			return 0;
		}
	}	
	else 
	{
		logMessage(LOG_ERROR_LEVEL, "fail to SEEK");
		return -1;
	}
}
