#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("Def", 150, 100)
{
    std::cout << "Def const called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Def", 145, 137), _target(target)
{
    std::cout << "Def const called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
: AForm(other)
{
    std::cout << "Copy const called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
    AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Def destructor called\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
  if (executor.getGrade() <= getToExecute())
  {
    std::ofstream targetFile;

    std::string filename = _target + "_shrubbery";
    targetFile.open(filename.c_str());
    if (targetFile.fail())
      std::cerr << "Error opening the outfile" << std::endl;
    targetFile << "                                                                    ..;===+. \n\
                                                                    .:=iiiiii=+= \n\
                                                                 .=i))=;::+)i=+, \n\
                                                              ,=i);)I)))I):=i=; \n\
                                                           .=i==))))ii)))I:i++ \n\
                                                         +)+))iiiiiiii))I=i+:' \n\
                                    .,:;;++++++;:,.       )iii+:::;iii))+i=' \n\
                                 .:;++=iiiiiiiiii=++;.    =::,,,:::=i));=+' \n\
                               ,;+==ii)))))))))))ii==+;,      ,,,:=i))+=: \n\
                             ,;+=ii))))))IIIIII))))ii===;.    ,,:=i)=i+ \n\
                            ;+=ii)))IIIIITIIIIII))))iiii=+,   ,:=));=, \n\
                          ,+=i))IIIIIITTTTTITIIIIII)))I)i=+,,:+i)=i+ \n\
                         ,+i))IIIIIITTTTTTTTTTTTI))IIII))i=::i))i=' \n\
                        ,=i))IIIIITLLTTTTTTTTTTIITTTTIII)+;+i)+i` \n\
                       =))ITTTTTTTTTTTLTTTTTTLLLLLLTi:=)IIiii; \n\
                      :))IIITTTTTLTTTTTTLLHLLLLL);=)II)IIIIi=: \n\
                      :i)IIITTTTTTTTTLLLHLLHLL)+=)II)ITTTI)i= \n\
                      .i)IIITTTTITTLLLHHLLLL);=)II)ITTTTII)i+ \n\
                    +i)i)))IITTLLLLLLLLT=:i)II)TTTTLTTIII)i; \n\
                  +ii)i:)IITTLLTLLLLT=;+i)I)ITTTTLTTTII))i; \n\
                 =;)i=:,=)ITTTTLTTI=:i))I)TTTLLLTTTTTII)i; \n\
               +i)ii::,  +)IIITI+:+i)I))TTTTLLTTTTTII))=, \n\
             :=;)i=:,,    ,i++::i))I)ITTTTTTTTTTIIII)=+' \n\
           .+ii)i=::,,   ,,::=i)))iIITTTTTTTTIIIII)=+ \n\
          ,==)ii=;:,,,,:::=ii)i)iIIIITIIITIIII))i+:' \n\
         +=:))i==;:::;=iii)+)=  `:i)))IIIII)ii+' \n\
       .+=:))iiiiiiii)))+ii; \n\
      .+=;))iiiiii)));ii+ \n\
     .+=i:)))))))=+ii+ \n\
    .;==i+::::=)i=; \n\
    ,+==iiiiii+, \n\
    `+=+++;`\n" << std::endl;
    targetFile.close();
    }               
    else
        throw ProblemToExecute();
}