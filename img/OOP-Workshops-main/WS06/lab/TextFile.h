#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>
namespace sdds
{

   class Line
   {
      // holds address of dynamically allocated string (to hold a line of file)
      char *m_value{nullptr};

      ///////////////////// METHODS /////////////////////
      // Returns the address held in the m_value attribute
      operator const char *() const;

      // Initializes the m_value attribute to nullptr.
      Line() {}

      // Dynamically allocates memory in m_value and copies the string pointed by lineContent into it.
      Line &operator=(const char *);

      // Makes sure all the allocated memory is freed.
      ~Line();

      // copy and copy assignment prevention goes here
      friend class TextFile;
   };

   class TextFile
   {
      // pointer to hold the dynamic array of Lines; initialized to nullptr
      Line *m_textLines;

      // ptr to hold the dynamic string holding file name; init to nullptr
      char *m_filename;

      // set to the number of lines in the file.
      unsigned m_noOfLines;

      // The page size is the number of lines that should be displayed on the screen before the display is paused. After these lines are displayed, the user must hit enter for the next page to appear.
      unsigned m_pageSize;

      // If the isCopy argument is false, dynamically allocates a Cstring in m_filename and copies the content of the fname argument into it. If the isCopy argument is true, dynamically allocates a Cstring in m_filename and copies the content of the fname argument with a prefix of "C_" attached to it
      void setFilename(const char *fname, bool isCopy = false);

      /*Counts the number of lines in the file:
      Creates a local ifstream object to open the file with the name held in m_filename. Then it will read the file, character by character, and accumulates the number of newlines in the m_noOfLines attribute.
      In the end, it will increase m_noOfLines by one, just in case, the last line does not have a new line at the end.
      If the number of lines is zero, it will delete the m_filename and set it to nullptr. (Setting the TextFile to a safe empty state)*/
      void setNoOfLines();

      void loadText();

      /*Saves the content of the TextFile under a new name.
   Use a local ofstream object to open a new file using the name kept in the argument filename. Then loop through the elements of the m_textLines array and write them in the opened file adding a new line to the end of each line.*/
      void saveAs(const char *fileName) const;

      // deletes the m_textLines dynamic array and sets is to nullptr deletes the m_filename dynamic Cstring and sets is to nullptr sets m_noOfLines attribute to zero.
      void setEmpty();

   public:
      // Creates an empty TextFile and initializes the m_pageSize attribute using the pageSize argument.
      TextFile(unsigned pageSize = 15);

      // Initializes the m_pageSize attribute using the pageSize argument and all the other attributes to nullptr and zero. Then if the filename is not null, it will set the filename, set the number of Lines and load the Text (using the corresponding private methods.)
      TextFile(const char *filename, unsigned pageSize = 15);

      TextFile(const TextFile &);

      TextFile &operator=(const TextFile &);

      ~TextFile();

      std::ostream &view(std::ostream &ostr) const;

      std::istream &getFile(std::istream &istr);

      operator bool() const;

      unsigned lines() const;

      const char *name() const;

      const char *operator[](unsigned index) const;
   };

   std::ostream &operator<<(std::ostream &ostr, const TextFile &text);
   std::istream &operator>>(std::istream &istr, TextFile &text);

}
#endif // !SDDS_TEXTFILE_H__
