package javaparser;

import com.github.javaparser.JavaParser;
import com.github.javaparser.ast.CompilationUnit;
import com.github.javaparser.ParseResult;
import com.github.javaparser.ast.PackageDeclaration;
import com.github.javaparser.ast.body.ClassOrInterfaceDeclaration;
import java.util.Optional;

public class javaparse {
	public static void main(String args[]) {
		if (args.length == 0)
			return;
		JavaParser parser = new JavaParser();
		ParseResult<CompilationUnit> res = parser.parse(args[0]);
		Optional<CompilationUnit> ocu = res.getResult();
		CompilationUnit cu = ocu.get();		
		
		//get the package name                                                                                                                                                                   
		Optional<PackageDeclaration> opd = cu.getPackageDeclaration();
		if (opd.isPresent() == true) {
			PackageDeclaration pd = opd.get();
			System.out.println(pd);
		}
		else
			System.out.println();

		//get the public class name
		cu.findAll(ClassOrInterfaceDeclaration.class).stream()
        .filter(f -> f.isPublic() && !f.isStatic()).forEach(f -> System.out.println(f.getName()));

	}	
}

