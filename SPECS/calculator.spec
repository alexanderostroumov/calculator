Name: calculator
Version: 1.0
Release: 1
Summary: Calculator
Group: Testing
License: GPL
URL: http://www.lug.mephist.ru
Source0: %{name}-%{version}.tar.gz
BuildRoot: /tmp/%{name}
BuildRequires: /bin/rm, /bin/mkdir, /bin/cp
Requires: /bin/bash

%description
Calculator
%prep

%setup -c %{name}

%build
make

%install
mkdir -p $RPM_BUILD_ROOT/usr/bin
cp %{name} $RPM_BUILD_ROOT/usr/bin

%clean
rm -rf $RPM_BUILD_ROOT

%files
/usr/bin/%{name}

%defattr(-,root,root,-)

#%doc
%attr(0755,root,root)/usr/bin/calculator

%changelog
* Thu May 21 2013 Ostroumov 
- Added /usr/local/bin/calculator
