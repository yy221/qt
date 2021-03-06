/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/


#include <stdio.h>

int main()
{
#if defined(__SYMBIAN32__)
    // Printing to stdout messes up the out.txt, so open a file and print there.
    FILE* file = fopen("c:\\logs\\qprocess_output_test.txt","w+");
    for (int i=0; i<200; i++) {
        fprintf(file, "%d -this is a number\n", i);
        fflush(file);
    }
    fclose(file);
#else
# if defined(_WIN32_WCE)
    for (int i=0; i<240; i++) {
# else //fprintf Output is very slow on Windows CE/Symbian
    for (int i=0; i<10240; i++) {
# endif
        fprintf(stdout, "%d -this is a number\n", i);
        fflush(stderr);
    }
#endif
    return 0;
}
