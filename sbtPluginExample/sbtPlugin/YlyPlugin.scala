import sbt.Keys._
import sbt._

object MySBTPlugin extends AutoPlugin {

  object autoImport {
    val hello = inputKey[Unit]("Says hello!")
  }
  import autoImport._
  override lazy val projectSettings = Seq(
    hello := {
      System.out.println("Hello")
    }
  )
}